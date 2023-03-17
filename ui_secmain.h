/********************************************************************************
** Form generated from reading UI file 'secmain.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECMAIN_H
#define UI_SECMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_secmain
{
public:
    QDialogButtonBox *okBox;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *secmain)
    {
        if (secmain->objectName().isEmpty())
            secmain->setObjectName(QStringLiteral("secmain"));
        secmain->resize(400, 300);
        okBox = new QDialogButtonBox(secmain);
        okBox->setObjectName(QStringLiteral("okBox"));
        okBox->setGeometry(QRect(30, 240, 341, 32));
        okBox->setOrientation(Qt::Horizontal);
        okBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textBrowser = new QTextBrowser(secmain);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(70, 20, 256, 192));

        retranslateUi(secmain);
        QObject::connect(okBox, SIGNAL(accepted()), secmain, SLOT(accept()));
        QObject::connect(okBox, SIGNAL(rejected()), secmain, SLOT(reject()));

        QMetaObject::connectSlotsByName(secmain);
    } // setupUi

    void retranslateUi(QDialog *secmain)
    {
        secmain->setWindowTitle(QApplication::translate("secmain", "Dialog", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("secmain", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Instructions - How to use the GUI?</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. Connect the ESP8266 to the USB Port.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. Press Connect button.</p>\n"
"<p style=\" margin-top:0px; margin"
                        "-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3. Once connected, press ON to turn on the sensor.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4. Press OFF if you wish to do so.</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class secmain: public Ui_secmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECMAIN_H
