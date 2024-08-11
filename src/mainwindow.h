#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>

#include <utils.h>
#include <vector>
#include "opencv2/opencv.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString file_name;
    QMessageBox message_box;
    Image image;
    std::vector<Image> images;
    std::vector<Image> gray_images;
    cv::Rect roi;
    Image roi_image;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_roi_button_clicked();

    void on_actionIntensity_Histogram_triggered();

    void on_tracking_button_clicked();

    void on_open_image_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
