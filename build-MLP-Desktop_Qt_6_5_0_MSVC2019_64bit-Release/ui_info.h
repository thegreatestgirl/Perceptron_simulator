/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName("Info");
        Info->resize(400, 300);
        textBrowser = new QTextBrowser(Info);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(-5, 60, 411, 192));

        retranslateUi(Info);

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QDialog *Info)
    {
        Info->setWindowTitle(QCoreApplication::translate("Info", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
