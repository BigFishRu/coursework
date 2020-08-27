#include "list_condition.h"
#include "ui_list_condition.h"

List_condition::List_condition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::List_condition)
{
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(counter);

}

List_condition::~List_condition()
{
    delete ui;
}

void List_condition::set_counter(int x){
    counter = x;
}
void List_condition::set_size(int x){
    size = x;
}

void List_condition::update(){
    if ((counter*100)/size > 0 || counter == 0){
    ui->progressBar->setValue((counter*100)/size);
    }
    else{
        ui->progressBar->setValue((counter*100)/size + 1);
    }

    ui->progressBar->update();
}
