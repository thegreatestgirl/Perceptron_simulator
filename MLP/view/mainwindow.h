#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QResizeEvent>
#include <QTimer>
#include <QWidget>

#include "controller/controller.h"
#include "drawwidget.h"
#include "info.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  QTimer *timer;
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Info *info_window;
  DrawWidget *draw_widget_;
  s21::Controller *controller_;
  std::vector<double> GetPixelsFromDrawer();
  std::vector<double> TakePixelsFromImg(QImage image);
  void DisplayAnswer(int answer, double probability);

 private slots:
  void slotTimer();
  void on_clear_graphics_view_button_clicked();
  void on_make_a_guess_button_clicked();
  void on_load_network_button_clicked();
  void on_create_network_button_clicked();
  void on_train_net_clicked();
  void on_load_bmp_clicked();
  void on_test_net_clicked();
  void on_save_net_clicked();

  void on_train_on_img_clicked();

signals:
  void signal_for_info(QString str);
};
#endif  // MAINWINDOW_H
