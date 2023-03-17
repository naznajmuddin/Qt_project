/********************************************************************************
** Form generated from reading UI file 'thirddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDDIALOG_H
#define UI_THIRDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ThirdDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *ThirdDialog)
    {
        if (ThirdDialog->objectName().isEmpty())
            ThirdDialog->setObjectName(QStringLiteral("ThirdDialog"));
        ThirdDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(ThirdDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ThirdDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 100, 261, 61));

        retranslateUi(ThirdDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ThirdDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ThirdDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ThirdDialog);
    } // setupUi

    void retranslateUi(QDialog *ThirdDialog)
    {
        ThirdDialog->setWindowTitle(QApplication::translate("ThirdDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ThirdDialog", "Name: Nazwa Najmuddin Bin Mohd Nizwaruddin\n"
"Matric Num: FB20083\n"
"Title: Project for Engineers Assignment", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ThirdDialog: public Ui_ThirdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDDIALOG_H
