#include "set_size.h"
#include "ui_set_size.h"


set_size::set_size(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::set_size)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setFixedSize(this->size());
    ui->widget->set_title("Задайте размер!");
}

set_size::~set_size()
{
    delete ui;
}

void set_size::on_buttonBox_accepted()
{
    size1 = ui->lineEdit->text().toInt();
    if (size1 > 0){
    ok_dont = true;
    }
    dont = false;
}
bool set_size::get_ok(){
    return ok_dont;
}
int set_size::get_size(){
    return size1;
}
void set_size::set_label(QString str){
    ui->label->setText(str);
}
bool set_size::get_dont(){
    return dont;
}
