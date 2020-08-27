#include "set_name.h"
#include "ui_set_name.h"

Set_name::Set_name(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Set_name)
{
    ui->setupUi(this);
    name = ui->lineEdit->text();
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setFixedSize(this->size());
    ui->widget->set_title("Задайте имя!");
}

Set_name::~Set_name()
{
    delete ui;
}

QString Set_name::get_name(){
    return name;
}
void Set_name::on_buttonBox_accepted()
{
    name = ui->lineEdit->text();
    ok_dont = true;
}
bool Set_name::get_ok(){
    return ok_dont;
}
void Set_name::set_label(QString str){
    ui->label->setText(str);
}
