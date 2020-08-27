 #include "stack_condition.h"
#include "ui_stack_condition.h"

Stack_condition::Stack_condition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stack_condition)
{
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(counter);


}

Stack_condition::~Stack_condition()
{
    delete ui;
}
void Stack_condition::set_counter(int x){
    counter = x;
}
void Stack_condition::set_size(int x){
    size = x;
}

void Stack_condition::update(){
    if ((counter*100)/size > 0 || counter == 0){
    ui->progressBar->setValue((counter*100)/size);
    }
    else{
        ui->progressBar->setValue((counter*100)/size + 1);
    }

    ui->progressBar->update();
}
