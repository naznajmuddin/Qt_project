/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMade_by_FB20083;
    QAction *actionTilt_Sensor_only_sends_digital_value;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QPushButton *instructions;
    QGridLayout *gridLayout;
    QLabel *tempLabel;
    QLCDNumber *tempLcdNumber;
    QGridLayout *gridLayout_2;
    QPushButton *btnConnect;
    QLabel *label;
    QPushButton *btnON;
    QPushButton *btnOFF;
    QCustomPlot *customPlot;
    QPushButton *aboutMe;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuClick_Me;
    QMenu *menuAssignment_PFE;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(442, 623);
        actionMade_by_FB20083 = new QAction(MainWindow);
        actionMade_by_FB20083->setObjectName(QStringLiteral("actionMade_by_FB20083"));
        actionTilt_Sensor_only_sends_digital_value = new QAction(MainWindow);
        actionTilt_Sensor_only_sends_digital_value->setObjectName(QStringLiteral("actionTilt_Sensor_only_sends_digital_value"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        instructions = new QPushButton(centralwidget);
        instructions->setObjectName(QStringLiteral("instructions"));

        gridLayout_3->addWidget(instructions, 0, 0, 1, 1, Qt::AlignLeft);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tempLabel = new QLabel(centralwidget);
        tempLabel->setObjectName(QStringLiteral("tempLabel"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        tempLabel->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        tempLabel->setFont(font);
        tempLabel->setAutoFillBackground(false);

        gridLayout->addWidget(tempLabel, 0, 1, 1, 1);

        tempLcdNumber = new QLCDNumber(centralwidget);
        tempLcdNumber->setObjectName(QStringLiteral("tempLcdNumber"));
        QPalette palette1;
        QBrush brush3(QColor(0, 0, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        tempLcdNumber->setPalette(palette1);
        tempLcdNumber->setAutoFillBackground(false);

        gridLayout->addWidget(tempLcdNumber, 0, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout, 7, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btnConnect = new QPushButton(centralwidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));

        gridLayout_2->addWidget(btnConnect, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 2, 1, 1);

        btnON = new QPushButton(centralwidget);
        btnON->setObjectName(QStringLiteral("btnON"));

        gridLayout_2->addWidget(btnON, 1, 0, 1, 1);

        btnOFF = new QPushButton(centralwidget);
        btnOFF->setObjectName(QStringLiteral("btnOFF"));

        gridLayout_2->addWidget(btnOFF, 1, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 8, 0, 1, 1);

        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));

        gridLayout_3->addWidget(customPlot, 9, 0, 1, 1);

        aboutMe = new QPushButton(centralwidget);
        aboutMe->setObjectName(QStringLiteral("aboutMe"));

        gridLayout_3->addWidget(aboutMe, 1, 0, 1, 1, Qt::AlignLeft);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 442, 26));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuClick_Me = new QMenu(menuBar);
        menuClick_Me->setObjectName(QStringLiteral("menuClick_Me"));
        menuAssignment_PFE = new QMenu(menuClick_Me);
        menuAssignment_PFE->setObjectName(QStringLiteral("menuAssignment_PFE"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuClick_Me->menuAction());
        menuClick_Me->addAction(menuAssignment_PFE->menuAction());
        menuClick_Me->addSeparator();
        menuAssignment_PFE->addAction(actionTilt_Sensor_only_sends_digital_value);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionMade_by_FB20083->setText(QApplication::translate("MainWindow", "Made by FB20083", Q_NULLPTR));
        actionTilt_Sensor_only_sends_digital_value->setText(QApplication::translate("MainWindow", "Made by FB20083", Q_NULLPTR));
        instructions->setText(QApplication::translate("MainWindow", "Instructions", Q_NULLPTR));
        tempLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; color:#0000ff;\">Air Quality Index</span></p></body></html>", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("MainWindow", "CONNECT", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        btnON->setText(QApplication::translate("MainWindow", "ON", Q_NULLPTR));
        btnOFF->setText(QApplication::translate("MainWindow", "OFF", Q_NULLPTR));
        aboutMe->setText(QApplication::translate("MainWindow", "About Me", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Main", Q_NULLPTR));
        menuClick_Me->setTitle(QApplication::translate("MainWindow", "Click Me!", Q_NULLPTR));
        menuAssignment_PFE->setTitle(QApplication::translate("MainWindow", "Assignment PFE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
