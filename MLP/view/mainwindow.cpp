#include "mainwindow.h"

#include <iostream>
#include <string>
#include <vector>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  setlocale(LC_NUMERIC, "C");
  ui->setupUi(this);
  controller_ = new s21::Controller();

  draw_widget_ = new DrawWidget();
  ui->graphicsView->setScene(draw_widget_);

  timer = new QTimer();
  connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
  timer->start(100);

  info_window = new Info();
  connect(this, &MainWindow::signal_for_info, info_window, &Info::slot_info);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::slotTimer() {
  timer->stop();
  draw_widget_->setSceneRect(0, 0, ui->graphicsView->width() - 20,
                             ui->graphicsView->height() - 20);
}

void MainWindow::on_clear_graphics_view_button_clicked() {
  draw_widget_->clear();
  ui->answer->clear();
  ui->answer_probability->clear();
}

std::vector<double> MainWindow::TakePixelsFromImg(QImage image) {
  QImage compressedImage = image.scaled(QSize(28, 28), Qt::KeepAspectRatio,
                                        Qt::SmoothTransformation);
  std::vector<double> pixels;
  std::cout << compressedImage.height() << " " << compressedImage.width()
            << std::endl;
  for (int y = 0; y < compressedImage.height(); ++y) {
    for (int x = 0; x < compressedImage.width(); ++x) {
      QRgb color = compressedImage.pixel(y, x);
      int intensity = qGray(color);
      pixels.push_back(double(intensity));
    }
    std::cout << std::endl;
  }
  for (size_t i = 0; i < pixels.size(); ++i) {
    if (pixels[i] > 0) {
      std::cout << "1 ";
    } else {
      std::cout << "0 ";
    }
    if (i % 28 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
  return pixels;
}

std::vector<double> MainWindow::GetPixelsFromDrawer() {
  QPixmap pixmap = ui->graphicsView->grab();
  std::vector<double> pixels = TakePixelsFromImg(pixmap.toImage());
  return pixels;
}

void MainWindow::on_make_a_guess_button_clicked() {
  std::vector<double> a = GetPixelsFromDrawer();
  if (controller_->GetNetworkPointer() != nullptr) {
      s21::NetworkAnswer answer = controller_->GetNetworkPointer()->MakeAGuess(a);
      std::cout << std::endl
                << answer.letter + 1 << " " << answer.probability << std::endl;
      DisplayAnswer(answer.letter, answer.probability);
  }
}

void MainWindow::on_load_network_button_clicked() {
  QString filter = "Object file (*.conf)";
  QString fileName = QFileDialog::getOpenFileName(this, "Open a file",
                                                  QDir::homePath(), filter);
  std::string file_name = fileName.toStdString();
  if (!fileName.isEmpty()) {
    std::cout << file_name << std::endl;
    if (ui->matrix_network->isChecked()) {
      controller_->SetNetworkPointer(new s21::MatrixNetwork());
    } else {
      controller_->SetNetworkPointer(new s21::GraphNetwork());
    }
    controller_->GetNetworkPointer()->LoadFromFile(file_name);
  }
}

void MainWindow::on_create_network_button_clicked() {
  std::cout << ui->hidden_layers_quantity->value() << std::endl;
  std::cout << ui->nq_on_first->value() << " " << ui->nq_on_second->value()
            << " " << ui->nq_on_third->value() << " "
            << ui->nq_on_fourth->value() << " " << ui->nq_on_fifth->value()
            << std::endl;
  std::cout << ui->matrix_network->isChecked() << " "
            << ui->graph_network->isChecked() << std::endl;

  std::vector<int> neurons_quantity_on_hidden_layers;
  neurons_quantity_on_hidden_layers.push_back(ui->nq_on_first->value());
  neurons_quantity_on_hidden_layers.push_back(ui->nq_on_second->value());
  neurons_quantity_on_hidden_layers.push_back(ui->nq_on_third->value());
  neurons_quantity_on_hidden_layers.push_back(ui->nq_on_fourth->value());
  neurons_quantity_on_hidden_layers.push_back(ui->nq_on_fifth->value());

  if (ui->matrix_network->isChecked()) {
    controller_->SetNetworkPointer(
        new s21::MatrixNetwork(ui->hidden_layers_quantity->value(),
                               neurons_quantity_on_hidden_layers, ui->output_classes_quantity->value()));
  } else {
    controller_->SetNetworkPointer(
        new s21::GraphNetwork(ui->hidden_layers_quantity->value(),
                              neurons_quantity_on_hidden_layers, ui->output_classes_quantity->value()));
  }
  std::cout << "creating net done" << std::endl;
}

void MainWindow::on_train_net_clicked() {
  QString filter = "Object file (*.csv)";
  QString fileName = QFileDialog::getOpenFileName(this, "Open a file",
                                                  QDir::homePath(), filter);
  std::string file_name = fileName.toStdString();
  if (!fileName.isEmpty() && controller_->GetNetworkPointer() != nullptr) {
    controller_->GetNetworkPointer()->Train(file_name,
                                            ui->epoch_quantity->value());
  }
  std::cout << "done" << std::endl;
}

void MainWindow::on_load_bmp_clicked() {
  QString filter = "Object file (*.bmp)";
  QString fileName = QFileDialog::getOpenFileName(this, "Open a file",
                                                  QDir::homePath(), filter);
  std::string file_name = fileName.toStdString();
  s21::NetworkAnswer answer;
  if (!fileName.isEmpty() && controller_->GetNetworkPointer() != nullptr) {
    QImage image(fileName);
    std::vector<double> a = TakePixelsFromImg(image);
    answer = controller_->GetNetworkPointer()->MakeAGuess(a);
  }
  std::cout << std::endl
            << "LOADED: " << answer.letter + 1 << " " << answer.probability
            << std::endl;
  DisplayAnswer(answer.letter, answer.probability);
}

void MainWindow::DisplayAnswer(int answer, double probability) {
//  char letter = (int)'A' + answer;
//  QString answr = "";
//  answr += letter;
  ui->answer->setAlignment(Qt::AlignHCenter);
  ui->answer_probability->setAlignment(Qt::AlignHCenter);
//  ui->answer->setText(answr);
  ui->answer->setText(QString::number(answer + 1));
  ui->answer_probability->setText(QString::number(probability));
}

void MainWindow::on_test_net_clicked() {
  QString filter = "Object file (*.csv)";
  QString fileName = QFileDialog::getOpenFileName(this, "Open a file",
                                                  QDir::homePath(), filter);
  std::string file_name = fileName.toStdString();
  std::vector<s21::RightAndNetworkAnswer> answers;
  if (!fileName.isEmpty() && controller_->GetNetworkPointer() != nullptr) {
    answers = controller_->GetNetworkPointer()->Test(file_name,
                                                    (ui->part_of_test->value() /  100));
    double right_answers_quantity = 0.0;
    for (size_t i = 0; i < answers.size(); ++i) {
//        avg_accuracy += answers[i].net_answer.probability;
        if (answers[i].right_answer[answers[i].net_answer.letter] == 1) right_answers_quantity++;
    }
    right_answers_quantity = right_answers_quantity / answers.size();
    std::cout << "done" << std::endl;
    emit signal_for_info("Network gave " + QString::number(right_answers_quantity * 100) + " percents of right answers");
    info_window->show();
  }
}

void MainWindow::on_save_net_clicked() {
  QDateTime nowDateTime;
  nowDateTime = QDateTime::currentDateTime();
  long long seconds = nowDateTime.toSecsSinceEpoch();
  QString path =
      QDir::homePath() + "/" + QString::number(seconds) + "_network.conf";
  if (controller_->GetNetworkPointer() != nullptr) {
      controller_->GetNetworkPointer()->SaveNetworkSettingToFile(
          path.toStdString());
      emit signal_for_info("Network saved at: " + path);
        info_window->show();

  }
}

void MainWindow::on_train_on_img_clicked()
{
    std::vector<double> input_signals = GetPixelsFromDrawer();
    if (controller_->GetNetworkPointer() != nullptr) {
        controller_->GetNetworkPointer()->TrainOnImg(input_signals, ui->right_class_number->value() - 1);
        controller_->GetNetworkPointer()->Print();
    }
}

