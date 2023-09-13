/********************************************************************************
** Form generated from reading UI file 'trainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINWINDOW_H
#define UI_TRAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_TrainWindow
{
public:

    void setupUi(QDialog *TrainWindow)
    {
        if (TrainWindow->objectName().isEmpty())
            TrainWindow->setObjectName(QString::fromUtf8("TrainWindow"));
        TrainWindow->resize(400, 300);

        retranslateUi(TrainWindow);

        QMetaObject::connectSlotsByName(TrainWindow);
    } // setupUi

    void retranslateUi(QDialog *TrainWindow)
    {
        TrainWindow->setWindowTitle(QCoreApplication::translate("TrainWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrainWindow: public Ui_TrainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINWINDOW_H
