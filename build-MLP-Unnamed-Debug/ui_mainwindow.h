/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *clear_graphics_view_button;
    QPushButton *make_a_guess_button;
    QLabel *answer;
    QPushButton *load_network_button;
    QSpinBox *hidden_layers_quantity;
    QLabel *label_2;
    QSpinBox *nq_on_first;
    QSpinBox *nq_on_second;
    QSpinBox *nq_on_third;
    QSpinBox *nq_on_fourth;
    QSpinBox *nq_on_fifth;
    QPushButton *create_network_button;
    QRadioButton *matrix_network;
    QRadioButton *graph_network;
    QPushButton *train_net;
    QPushButton *load_bmp;
    QSpinBox *epoch_quantity;
    QLabel *label_3;
    QDoubleSpinBox *part_of_test;
    QLabel *label_4;
    QPushButton *test_net;
    QLabel *answer_probability;
    QPushButton *save_net;
    QLabel *label;
    QLabel *label_5;
    QSpinBox *output_classes_quantity;
    QPushButton *train_on_img;
    QLabel *label_6;
    QSpinBox *right_class_number;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(937, 861);
        MainWindow->setStyleSheet(QString::fromUtf8("color:  #19822d;\n"
"background-color: #1a1d1b;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 30, 400, 400));
        graphicsView->setMaximumSize(QSize(500, 500));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: #000;\n"
"border-radius: 5px;"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        clear_graphics_view_button = new QPushButton(centralwidget);
        clear_graphics_view_button->setObjectName(QString::fromUtf8("clear_graphics_view_button"));
        clear_graphics_view_button->setGeometry(QRect(20, 440, 190, 41));
        clear_graphics_view_button->setCursor(QCursor(Qt::PointingHandCursor));
        clear_graphics_view_button->setStyleSheet(QString::fromUtf8("color:  #19822d;\n"
"border: 2px solid #19822d;\n"
"font-size: 20px;\n"
"border-radius: 5px;"));
        make_a_guess_button = new QPushButton(centralwidget);
        make_a_guess_button->setObjectName(QString::fromUtf8("make_a_guess_button"));
        make_a_guess_button->setGeometry(QRect(229, 490, 191, 41));
        make_a_guess_button->setCursor(QCursor(Qt::PointingHandCursor));
        make_a_guess_button->setStyleSheet(QString::fromUtf8("color:  #19822d;\n"
"border: 2px solid #19822d;\n"
"font-size: 20px;\n"
"border-radius: 5px;"));
        answer = new QLabel(centralwidget);
        answer->setObjectName(QString::fromUtf8("answer"));
        answer->setGeometry(QRect(510, 30, 400, 400));
        answer->setStyleSheet(QString::fromUtf8("background-color: #3d3d3d;\n"
"border-radius: 5px;\n"
"font-size: 300px;"));
        answer->setLineWidth(1);
        answer->setTextFormat(Qt::AutoText);
        answer->setMargin(20);
        load_network_button = new QPushButton(centralwidget);
        load_network_button->setObjectName(QString::fromUtf8("load_network_button"));
        load_network_button->setGeometry(QRect(20, 800, 161, 41));
        load_network_button->setCursor(QCursor(Qt::PointingHandCursor));
        load_network_button->setStyleSheet(QString::fromUtf8("color:  #19822d;\n"
"border: 2px solid #19822d;\n"
"font-size: 20px;\n"
"border-radius: 5px;"));
        hidden_layers_quantity = new QSpinBox(centralwidget);
        hidden_layers_quantity->setObjectName(QString::fromUtf8("hidden_layers_quantity"));
        hidden_layers_quantity->setGeometry(QRect(210, 610, 42, 22));
        hidden_layers_quantity->setMinimum(2);
        hidden_layers_quantity->setMaximum(5);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 610, 171, 16));
        nq_on_first = new QSpinBox(centralwidget);
        nq_on_first->setObjectName(QString::fromUtf8("nq_on_first"));
        nq_on_first->setGeometry(QRect(20, 650, 42, 22));
        nq_on_first->setMinimum(1);
        nq_on_first->setMaximum(1000);
        nq_on_first->setValue(100);
        nq_on_second = new QSpinBox(centralwidget);
        nq_on_second->setObjectName(QString::fromUtf8("nq_on_second"));
        nq_on_second->setGeometry(QRect(70, 650, 42, 22));
        nq_on_second->setMinimum(1);
        nq_on_second->setMaximum(1000);
        nq_on_second->setValue(100);
        nq_on_third = new QSpinBox(centralwidget);
        nq_on_third->setObjectName(QString::fromUtf8("nq_on_third"));
        nq_on_third->setGeometry(QRect(120, 650, 42, 22));
        nq_on_third->setMinimum(1);
        nq_on_third->setMaximum(1000);
        nq_on_third->setValue(100);
        nq_on_fourth = new QSpinBox(centralwidget);
        nq_on_fourth->setObjectName(QString::fromUtf8("nq_on_fourth"));
        nq_on_fourth->setGeometry(QRect(170, 650, 42, 22));
        nq_on_fourth->setMinimum(1);
        nq_on_fourth->setMaximum(1000);
        nq_on_fourth->setValue(100);
        nq_on_fifth = new QSpinBox(centralwidget);
        nq_on_fifth->setObjectName(QString::fromUtf8("nq_on_fifth"));
        nq_on_fifth->setGeometry(QRect(220, 650, 42, 22));
        nq_on_fifth->setMinimum(1);
        nq_on_fifth->setMaximum(1000);
        nq_on_fifth->setValue(100);
        create_network_button = new QPushButton(centralwidget);
        create_network_button->setObjectName(QString::fromUtf8("create_network_button"));
        create_network_button->setGeometry(QRect(20, 750, 161, 41));
        create_network_button->setCursor(QCursor(Qt::PointingHandCursor));
        create_network_button->setStyleSheet(QString::fromUtf8("color:  #19822d;\n"
"border: 2px solid #19822d;\n"
"font-size: 20px;\n"
"border-radius: 5px;"));
        matrix_network = new QRadioButton(centralwidget);
        matrix_network->setObjectName(QString::fromUtf8("matrix_network"));
        matrix_network->setGeometry(QRect(20, 630, 99, 20));
        matrix_network->setChecked(true);
        graph_network = new QRadioButton(centralwidget);
        graph_network->setObjectName(QString::fromUtf8("graph_network"));
        graph_network->setGeometry(QRect(130, 630, 99, 20));
        train_net = new QPushButton(centralwidget);
        train_net->setObjectName(QString::fromUtf8("train_net"));
        train_net->setGeometry(QRect(200, 750, 161, 41));
        train_net->setCursor(QCursor(Qt::PointingHandCursor));
        train_net->setStyleSheet(QString::fromUtf8("color:  #19822d;\n"
"border: 2px solid #19822d;\n"
"font-size: 20px;\n"
"border-radius: 5px;"));
        load_bmp = new QPushButton(centralwidget);
        load_bmp->setObjectName(QString::fromUtf8("load_bmp"));
        load_bmp->setGeometry(QRect(230, 440, 190, 41));
        load_bmp->setCursor(QCursor(Qt::PointingHandCursor));
        load_bmp->setStyleSheet(QString::fromUtf8("color:  #19822d;\n"
"border: 2px solid #19822d;\n"
"font-size: 20px;\n"
"border-radius: 5px;"));
        epoch_quantity = new QSpinBox(centralwidget);
        epoch_quantity->setObjectName(QString::fromUtf8("epoch_quantity"));
        epoch_quantity->setGeometry(QRect(210, 710, 42, 22));
        epoch_quantity->setMinimum(1);
        epoch_quantity->setMaximum(1000);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 710, 171, 16));
        part_of_test = new QDoubleSpinBox(centralwidget);
        part_of_test->setObjectName(QString::fromUtf8("part_of_test"));
        part_of_test->setGeometry(QRect(850, 760, 62, 22));
        part_of_test->setMaximum(100.000000000000000);
        part_of_test->setSingleStep(1.000000000000000);
        part_of_test->setValue(100.000000000000000);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(680, 760, 161, 16));
        test_net = new QPushButton(centralwidget);
        test_net->setObjectName(QString::fromUtf8("test_net"));
        test_net->setGeometry(QRect(680, 800, 231, 41));
        test_net->setCursor(QCursor(Qt::PointingHandCursor));
        test_net->setStyleSheet(QString::fromUtf8("color:  #19822d;\n"
"border: 2px solid #19822d;\n"
"font-size: 20px;\n"
"border-radius: 5px;"));
        answer_probability = new QLabel(centralwidget);
        answer_probability->setObjectName(QString::fromUtf8("answer_probability"));
        answer_probability->setGeometry(QRect(510, 440, 400, 91));
        answer_probability->setStyleSheet(QString::fromUtf8("background-color: #3d3d3d;\n"
"border-radius: 5px;\n"
"font-size: 30px;"));
        answer_probability->setLineWidth(1);
        answer_probability->setTextFormat(Qt::AutoText);
        answer_probability->setMargin(20);
        save_net = new QPushButton(centralwidget);
        save_net->setObjectName(QString::fromUtf8("save_net"));
        save_net->setGeometry(QRect(380, 750, 161, 41));
        save_net->setCursor(QCursor(Qt::PointingHandCursor));
        save_net->setStyleSheet(QString::fromUtf8("color:  #19822d;\n"
"border: 2px solid #19822d;\n"
"font-size: 20px;\n"
"border-radius: 5px;"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(565, 40, 290, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 590, 241, 16));
        output_classes_quantity = new QSpinBox(centralwidget);
        output_classes_quantity->setObjectName(QString::fromUtf8("output_classes_quantity"));
        output_classes_quantity->setGeometry(QRect(270, 590, 42, 22));
        output_classes_quantity->setMinimum(1);
        output_classes_quantity->setMaximum(100);
        output_classes_quantity->setValue(26);
        train_on_img = new QPushButton(centralwidget);
        train_on_img->setObjectName(QString::fromUtf8("train_on_img"));
        train_on_img->setGeometry(QRect(20, 490, 191, 41));
        train_on_img->setCursor(QCursor(Qt::PointingHandCursor));
        train_on_img->setStyleSheet(QString::fromUtf8("color:  #19822d;\n"
"border: 2px solid #19822d;\n"
"font-size: 20px;\n"
"border-radius: 5px;"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 540, 181, 16));
        right_class_number = new QSpinBox(centralwidget);
        right_class_number->setObjectName(QString::fromUtf8("right_class_number"));
        right_class_number->setGeometry(QRect(210, 540, 42, 22));
        right_class_number->setMinimum(1);
        right_class_number->setMaximum(100);
        right_class_number->setValue(1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        clear_graphics_view_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        make_a_guess_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        answer->setText(QString());
        load_network_button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201\320\265\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\272\321\200\321\213\321\202\321\213\321\205 \321\201\320\273\320\276\320\265\320\262", nullptr));
        create_network_button->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\320\265\321\202\321\214", nullptr));
        matrix_network->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\321\200\320\270\321\207\320\275\320\260\321\217", nullptr));
        graph_network->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\276\320\262\320\260\321\217", nullptr));
        train_net->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\203\321\207\320\270\321\202\321\214 \321\201\320\265\321\202\321\214", nullptr));
        load_bmp->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 BMP", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\215\320\277\320\276\321\205 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\321\214 \321\202\320\265\321\201\321\202\320\276\320\262\320\276\320\271 \320\262\321\213\320\261\320\276\321\200\320\272\320\270", nullptr));
        test_net->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\320\265\321\202\321\214", nullptr));
        answer_probability->setText(QString());
        save_net->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\201\320\265\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\275\320\276\320\263\320\276 \320\272\320\273\320\260\321\201\321\201\320\260 (\320\275\321\203\320\274\320\265\321\200\320\260\321\206\320\270\321\217 \321\201 1)", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\262\320\260\320\265\320\274\321\213\321\205 \320\272\320\273\320\260\321\201\321\201\320\276\320\262", nullptr));
        train_on_img->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\203\321\207\320\270\321\202\321\214 \320\275\320\260 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\265", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\320\263\320\276 \320\272\320\273\320\260\321\201\321\201\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
