#include "info.h"

#include "ui_info.h"

Info::Info(QWidget *parent) : QDialog(parent), ui(new Ui::Info) {
  ui->setupUi(this);
}

Info::~Info() { delete ui; }

void Info::slot_info(QString str) { ui->textBrowser->setText(str); }
