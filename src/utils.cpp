#include "utils.h"
#include <QtCharts>

void calculate_intensity_histogram(Image& source) {

    int histSize = 256;
    source.histogram.resize(histSize, 0);

    for (int y = 0; y < source.mat.rows; ++y) {
        for (int x = 0; x < source.mat.cols; ++x) {
            int pixelValue = static_cast<int>(source.mat.at<uchar>(y, x));
            source.histogram[pixelValue]++;
        }
    }
}

void show_histogram(std::vector<double>histogram)
{
    QBarSet *barSet = new QBarSet("Histogram Values");
    barSet->setColor(QColor(0,0,0));
    for (int i = 0; i < 256; i++) {
        *barSet << histogram[i];
    }
    
    QBarSeries *series = new QBarSeries();
    series->append(barSet);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Histogram");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(0, 255);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QWidget *window = new QWidget;
    window->setMinimumSize(1024,768);
    window->setWindowTitle("Intensity Histogram");
    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(chartView);
    window->setLayout(lay);
    window->show();
}

double dot_product(const std::vector<double>& v1, const std::vector<double>& v2) {
    double result = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

double norm(const std::vector<double>& v) {
    double sumOfSquares = 0.0;
    for (double val : v) {
        sumOfSquares += val * val;
    }
    return std::sqrt(sumOfSquares);
}

double cosine_similarity(const std::vector<double>& v1, const std::vector<double>& v2) {
    double dot = dot_product(v1, v2);
    double normV1 = norm(v1);
    double normV2 = norm(v2);

    if (normV1 == 0 || normV2 == 0) {
        return 0.0;
    }

    return dot / (normV1 * normV2);
}

double intersection(const std::vector<double>& hist1, const std::vector<double>& hist2) {
    if (hist1.size() != hist2.size() || hist1.size() == 0) {
        return 0.0;
    }

    double intersection = 0.0;
    for (size_t i = 0; i < hist1.size(); i++) {
        intersection += std::min(hist1[i], hist2[i]);
    }

    return intersection;
}

double euclidean_distance(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::runtime_error("Vektör boyutları eşleşmiyor.");
    }

    double sum = 0.0;
    for (size_t i = 0; i < vec1.size(); i++) {
        double diff = vec1[i] - vec2[i];
        sum += diff * diff;
    }

    return std::sqrt(sum);
}

double mean(const std::vector<double>& vec) {
    double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return sum / vec.size();
}

double correlation(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    if (vec1.size() != vec2.size() || vec1.size() == 0) {
        throw std::invalid_argument("Vektör boyutları eşleşmiyor.");
    }

    double mean1 = mean(vec1);
    double mean2 = mean(vec2);

    double numerator = 0.0;
    double denominator1 = 0.0;
    double denominator2 = 0.0;

    for (size_t i = 0; i < vec1.size(); i++) {
        double diff1 = vec1[i] - mean1;
        double diff2 = vec2[i] - mean2;
        numerator += diff1 * diff2;
        denominator1 += diff1 * diff1;
        denominator2 += diff2 * diff2;
    }

    double correlation = numerator / (std::sqrt(denominator1) * std::sqrt(denominator2));
    return correlation;
}
