#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <QDebug>
#include <QElapsedTimer>
#include <QtCharts>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_roi_button_clicked()
{
    roi = selectROI("Select Area", image.mat);
    cv::destroyAllWindows();

    roi_image.mat = image.mat(roi);
    cvtColor(roi_image.mat, roi_image.mat, cv::COLOR_BGR2GRAY);
    calculate_intensity_histogram(roi_image);
    imshow("Selected Area", roi_image.mat);
}


void MainWindow::on_actionIntensity_Histogram_triggered()
{
    show_histogram(roi_image.histogram);
}


void MainWindow::on_tracking_button_clicked()
{
    QString data_set_name = ui->data_set_combo_box->currentText().toLower();
    int number_of_frames = ui->frames_line_edit->text().toInt();
    if (number_of_frames == 0) {
        number_of_frames = images.size();
    }

    QVector<double> similarity_values;
    for(int i = 0; i < number_of_frames; i++) {

        QElapsedTimer timer;
        timer.start();

        cv::Mat frame = gray_images[i].mat.clone();
        cv::Mat color_frame = images[i].mat.clone();


        int centerX = (roi.x + (roi.width / 2));
        int centerY = (roi.y + (roi.height / 2));

        int x_start = std::max(0, static_cast<int>(centerX) - (int)roi.width);
        int y_start = std::max(0, static_cast<int>(centerY) - (int)roi.height);

        int x_end = std::min(frame.cols, static_cast<int>(centerX) + (int)roi.width);
        int y_end = std::min(frame.rows, static_cast<int>(centerY) + (int)roi.height);

        cv::Point pt1(x_start, y_start);
        cv::Point pt2(x_end, y_end);
        rectangle(color_frame, pt1, pt2, cv::Scalar(0, 0, 255), 2);

        rectangle(color_frame, roi, cv::Scalar(255, 0, 0), 2);

        cv::Rect best_search_window = roi;
        double max_value = -1;

        int spiralRadius = 1;
        int maxSpiralRadius = std::min(x_end - x_start, y_end - y_start) / 2;

        while (spiralRadius <= maxSpiralRadius) {
            for (double angle = 0; angle < 2 * M_PI; angle += 0.1) {
                int x = centerX + static_cast<int>(spiralRadius * cos(angle));
                int y = centerY + static_cast<int>(spiralRadius * sin(angle));

                if (x>= 0 && x + roi.width < frame.cols && x + roi.width < x_end && y >= 0 && y + roi.height < frame.rows &&  y + roi.height < y_end) {
                    cv::Rect search_window(x, y, roi.width, roi.height);

                    Image image;
                    image.mat = frame(search_window);
                    calculate_intensity_histogram(image);

                    double similarity = correlation(roi_image.histogram, image.histogram);

                    if (similarity > max_value) {
                        max_value = similarity;
                        best_search_window = search_window;
                    }
                }
            }
            spiralRadius++;
        }

        //        for (int y = y_start; y < y_end && y < frame.rows; y+=2)
        //        {
        //            for (int x = x_start; x < x_end && x < frame.cols; x+=2)
        //            {
        //                cv::Rect search_window(x, y, roi.width, roi.height);
        //                if (x + search_window.width < frame.cols && y + search_window.height < frame.rows && x + search_window.width < x_end && y + search_window.height < y_end) {
        //                    Image image;
        //                    image.mat = frame(search_window);
        //                    calculate_intensity_histogram(image);

        //                    double similarity = correlation(roi_image.histogram, image.histogram);

        //                    if (similarity > max_value) {
        //                        max_value = similarity;
        //                        best_search_window = search_window;
        //                    }
        //                }
        //            }
        //        }

        similarity_values.push_back(max_value);
        roi = best_search_window;
        rectangle(color_frame, roi, cv::Scalar(0, 255, 0), 2);



        qint64 elapsedTime = timer.elapsed(); // Geçen süre milisaniye cinsinden.
        qDebug() << "Iterasyon" << i << "Sure:" << elapsedTime / 1000.0 << "sn" << "Similarity" << max_value; // Saniyeye çevirerek yazdır.
        imwrite("../output_images/tracking_object" + std::to_string(i+1) + ".jpg", color_frame);
        QImage image = QImage(color_frame.data, color_frame.cols, color_frame.rows, color_frame.step, QImage::Format_BGR888);
        QPixmap pixmap = QPixmap::fromImage(image);

        ui->image_label->setPixmap(pixmap);
        ui->image_label->setScaledContents(true);
        ui->image_label->update();
        qApp->processEvents();
    }

    QLineSeries *series = new QLineSeries();
    for (int j = 0; j < similarity_values.size(); ++j) {
        series->append(j + 1, similarity_values[j]);
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Similarity Values Over Frames");
    chart->createDefaultAxes();

    QValueAxis *xAxis = qobject_cast<QValueAxis *>(chart->axes(Qt::Horizontal).back());
    QValueAxis *yAxis = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).back());
    xAxis->setTitleText("Frame");
    yAxis->setTitleText("Similarity");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QWidget *window = new QWidget;
    window->setMinimumSize(1024,768);
    window->setWindowTitle("Similarity Values");
    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(chartView);
    window->setLayout(lay);
    window->show();
}

void MainWindow::on_open_image_button_clicked() {

    QString data_set_name = ui->data_set_combo_box->currentText().toLower();

    this->image.mat = cv::imread("../data_sets/" + data_set_name.toStdString() + "/0001.jpg");
    QImage img = QImage((uchar*)image.mat.data, image.mat.cols, image.mat.rows, QImage::Format_BGR888);
    QPixmap pixel = QPixmap::fromImage(img);
    ui->image_label->setPixmap(pixel);
    ui->image_label->setScaledContents(true);

    std::string folderPath = "../data_sets/" + data_set_name.toStdString() + "/";

    images.clear();
    std::vector<std::string> fileList;
    cv::glob(folderPath, fileList);

    for (const auto& filePath : fileList) {
        Image image;
        image.mat = cv::imread(filePath);

        if (!image.mat.empty()) {
            images.push_back(image);
            cv::cvtColor(image.mat, image.mat, cv::COLOR_BGR2GRAY);
            gray_images.push_back(image);
        }
        else {
            std::cerr << "Resim okunamadı: " << filePath << std::endl;
        }
    }

}

