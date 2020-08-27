#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent, Qt::Window | Qt::FramelessWindowHint),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap* photo = new QPixmap("://image/burgan.GysTD.jpg");
    ui->label_2->setPixmap(*photo);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setFixedSize(this->size());
    ui->widget->set_title("ОШИБКА!");
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::set_label(QString str){
    ui->label->setText(str);
}
