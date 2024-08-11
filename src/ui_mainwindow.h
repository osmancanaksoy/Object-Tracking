/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionIntensity_Histogram;
    QAction *actionNormalize_Histogram;
    QAction *actionColor_Histogram;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *image_label;
    QLabel *data_set_label;
    QComboBox *data_set_combo_box;
    QLineEdit *frames_line_edit;
    QPushButton *open_image_button;
    QPushButton *roi_button;
    QPushButton *tracking_button;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuHistogram;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(787, 453);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionIntensity_Histogram = new QAction(MainWindow);
        actionIntensity_Histogram->setObjectName(QString::fromUtf8("actionIntensity_Histogram"));
        actionNormalize_Histogram = new QAction(MainWindow);
        actionNormalize_Histogram->setObjectName(QString::fromUtf8("actionNormalize_Histogram"));
        actionColor_Histogram = new QAction(MainWindow);
        actionColor_Histogram->setObjectName(QString::fromUtf8("actionColor_Histogram"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(200, 25));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);

        gridLayout->addWidget(label, 3, 1, 1, 1);

        image_label = new QLabel(centralwidget);
        image_label->setObjectName(QString::fromUtf8("image_label"));
        image_label->setMaximumSize(QSize(16777215, 500));

        gridLayout->addWidget(image_label, 0, 0, 1, 3);

        data_set_label = new QLabel(centralwidget);
        data_set_label->setObjectName(QString::fromUtf8("data_set_label"));
        data_set_label->setMaximumSize(QSize(150, 16));
        data_set_label->setFont(font);

        gridLayout->addWidget(data_set_label, 1, 1, 1, 1);

        data_set_combo_box = new QComboBox(centralwidget);
        data_set_combo_box->addItem(QString());
        data_set_combo_box->addItem(QString());
        data_set_combo_box->addItem(QString());
        data_set_combo_box->addItem(QString());
        data_set_combo_box->addItem(QString());
        data_set_combo_box->setObjectName(QString::fromUtf8("data_set_combo_box"));

        gridLayout->addWidget(data_set_combo_box, 2, 1, 1, 1);

        frames_line_edit = new QLineEdit(centralwidget);
        frames_line_edit->setObjectName(QString::fromUtf8("frames_line_edit"));
        frames_line_edit->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(frames_line_edit, 4, 1, 1, 1);

        open_image_button = new QPushButton(centralwidget);
        open_image_button->setObjectName(QString::fromUtf8("open_image_button"));

        gridLayout->addWidget(open_image_button, 2, 0, 1, 1);

        roi_button = new QPushButton(centralwidget);
        roi_button->setObjectName(QString::fromUtf8("roi_button"));

        gridLayout->addWidget(roi_button, 3, 0, 1, 1);

        tracking_button = new QPushButton(centralwidget);
        tracking_button->setObjectName(QString::fromUtf8("tracking_button"));

        gridLayout->addWidget(tracking_button, 2, 2, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 787, 22));
        menuHistogram = new QMenu(menubar);
        menuHistogram->setObjectName(QString::fromUtf8("menuHistogram"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHistogram->menuAction());
        menuHistogram->addAction(actionIntensity_Histogram);
        menuHistogram->addAction(actionColor_Histogram);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionIntensity_Histogram->setText(QCoreApplication::translate("MainWindow", "Intensity Histogram", nullptr));
        actionNormalize_Histogram->setText(QCoreApplication::translate("MainWindow", "Normalize Histogram", nullptr));
        actionColor_Histogram->setText(QCoreApplication::translate("MainWindow", "Color Histogram", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Number Of Frames:", nullptr));
        image_label->setText(QString());
        data_set_label->setText(QCoreApplication::translate("MainWindow", "Select Data Set:", nullptr));
        data_set_combo_box->setItemText(0, QCoreApplication::translate("MainWindow", "Ball", nullptr));
        data_set_combo_box->setItemText(1, QCoreApplication::translate("MainWindow", "YellowBall", nullptr));
        data_set_combo_box->setItemText(2, QCoreApplication::translate("MainWindow", "Player", nullptr));
        data_set_combo_box->setItemText(3, QCoreApplication::translate("MainWindow", "Erase", nullptr));
        data_set_combo_box->setItemText(4, QCoreApplication::translate("MainWindow", "Hand", nullptr));

        frames_line_edit->setText(QString());
        open_image_button->setText(QCoreApplication::translate("MainWindow", "Open Image", nullptr));
        roi_button->setText(QCoreApplication::translate("MainWindow", "Select ROI", nullptr));
        tracking_button->setText(QCoreApplication::translate("MainWindow", "Start Tracking", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Stop Tracking", nullptr));
        menuHistogram->setTitle(QCoreApplication::translate("MainWindow", "Histogram", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
