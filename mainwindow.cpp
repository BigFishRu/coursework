#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "set_name.h"
#include "set_size.h"
#include "stack_condition.h"
#include <QMouseEvent>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlag(Qt::FramelessWindowHint);
   // this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    ui->input_up->hide();
    ui->input_down->hide();
    ui->input_list->hide();
    ui->search_list->hide();
    ui->delete_list->hide();
    ui->progress_list->hide();
    ui->widget->set_title("Стек списков");

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(update_list_widget()));
    timer->start(60);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::get_dx(){
    return dx;
}
int MainWindow::get_dy(){
    return dy;
}
void MainWindow::set_dx(int x){
    dx = x;
}
void MainWindow::set_dy(int x){
    dy = x;
}


void MainWindow::update_list_widget(){
   if (stk->check_empty() != true){
          if (ui->stack->currentRow() >= 0){
              int index = stk->search_element(ui->stack->item(ui->stack->currentRow())->text());
              list* point = &stk->get_arr()[index];


              if(point->get_size() > 0){
                 ui->progress_list->show();
                 ui->progress_list->set_size(point->get_size());
                 ui->progress_list->set_counter(point->get_counter());
                 ui->progress_list->update();
              }
              else ui->progress_list->hide();

              ui->input_list->show();
              ui->delete_list->show();
              ui->search_list->show();

              if (stk->get_arr()[stk->search_element(ui->stack->item(ui->stack->currentRow())->text())].get_counter() > 0){
                  ui->input_up->show();
                  ui->input_down->show();
              }
              else if (stk->get_arr()[stk->search_element(ui->stack->item(ui->stack->currentRow())->text())].get_counter() == 0 && ui->input_up->isHidden() != true){
                  ui->input_up->hide();
                  ui->input_down->hide();
              }


             if (current_row_prev != ui->stack->currentRow()){

                 ui->list->clear();


                 for(int index = 0;index != point->get_counter();index++){
                   ui->list->addItem(point->get_arr()[index]);

                 }
                 current_row_prev = ui->stack->currentRow();
             }
          }
          else ui->list->clear();
   }
   else{
       ui->input_list->hide();
       ui->delete_list->hide();
       ui->search_list->hide();
       ui->progress_list->hide();
       ui->input_up->hide();
       ui->input_down->hide();
       ui->list->clear();

   }

}

void MainWindow::on_input_stack_clicked()
{

    if (stk->get_size() == 0){
        set_size ss;
        ss.set_label("Задайте размер стека");
        ss.exec();
        if(ss.get_dont() == false){
            if (ss.get_ok() == true){
                stk->set_size(ss.get_size());

                stk->set_arr();
            }
            else{
                error->set_label("Введите целое число или число > 0");
                error->exec();

                return;
            }
        }
        else return;
    }
    if(stk->check_full()!= true){

        ui->progress_stack->set_size(stk->get_size());
        Set_name sm ;
        sm.set_label("Задайте имя");
        sm.exec();
        if (stk->search_element(sm.get_name()) == -1){
            if (sm.get_ok() == true){
                stk->input_element(sm.get_name());
                ui->stack->addItem(stk->get_arr()[stk->get_counter() - 1].name);
                ui->progress_stack->set_counter(stk->get_counter());
                ui->progress_stack->update();
            }
        }
        else {
            error->set_label("Такой элемент уже существует");
            error->exec();
        }
    }
    else {
        error->set_label("Стек полный, добавление невозможно");
        error->exec();
    }
}

void MainWindow::on_delete_stack_clicked()
{
    if(stk->check_empty() != true){
        ui->stack->removeItemWidget(ui->stack->takeItem(stk->get_counter() - 1));
        stk->delete_element();
        ui->progress_stack->set_counter(stk->get_counter());
        ui->progress_stack->update();
    }
    else {
        error->set_label("Стек пустой,Удаление невозможно");
        error->exec();
    }
}

void MainWindow::on_search_stack_clicked()
{
    Set_name sn;
    sn.set_label("Введите имя искомого элемента");
    sn.exec();
    int index = stk->search_element(sn.get_name());
    if (index != -1){
        ui->stack->setCurrentRow(index);
    }
    else {
        error->set_label("Такого элемента нет");
        error->exec();
    }
}

void MainWindow::on_input_list_clicked()
{
    list* point = &stk->get_arr()[stk->search_element(ui->stack->item(ui->stack->currentRow())->text())];
    if (point->get_size() == 0){
        set_size ss;
        ss.set_label("Задайте размер списка");
        ss.exec();
        if(ss.get_dont() == false){
            if (ss.get_ok() == true){
                point->set_size(ss.get_size());
                point->set_arr();
            }
            else{
                error->set_label("Введите целое число или число > 0");
                error->exec();
                return;
            }
        }
        else {
            return;
        }
    }
    if(point->check_full()!= true){

        if(ui->list->currentRow() < 0 && point->get_counter() != 0){
            error->set_label("выберите элемент");
            error->exec();
            return;
        }
        Set_name sm ;
        sm.set_label("Задайте название ячейки");
        sm.exec();
        ui->progress_list->set_size(point->get_size());

        if (sm.get_ok() == true){

            if(point->search_element(sm.get_name()) != -1){
                error->set_label("такой элемент уже существует");
                error->exec();
                return;
            }

            if(ui->input_up->isChecked() == true && ui->list->currentRow() >= 0 ){

                ui->list->insertItem(ui->list->currentRow(), point->input_up(sm.get_name(), ui->list->currentRow()));
               //  ui->list->addItem(point->get_arr()[point->get_counter() - 1]);
            }
            else if(ui->input_down->isChecked() == true && ui->list->currentRow() >= 0 ){

                 ui->list->insertItem(ui->list->currentRow() + 1, point->input_down(sm.get_name(), ui->list->currentRow()));
            }
            else if(point->get_counter() == 0){
                if(point->input_element(sm.get_name()) != true){
                   return;
                }
                ui->list->addItem(point->get_arr()[point->get_counter() - 1]);
            }
            ui->progress_list->set_counter(point->get_counter());
            ui->progress_list->update();
        }
    }
    else{
        error->set_label("Cписок пустой");
        error->exec();
    }
}

void MainWindow::on_delete_list_clicked()
{
    list* point = &stk->get_arr()[stk->search_element(ui->stack->item(ui->stack->currentRow())->text())];
    if (ui->list->currentRow() >= 0){

        point->delete_element(ui->list->currentRow());
        ui->stack->removeItemWidget(ui->list->takeItem(ui->list->currentRow()));
    }
    else if(point->check_empty() == true){
        error->set_label("список пуст удаление невозможно");
        error->exec();
    }
    else {
        error->set_label("Выберите элемент");
        error->exec();
    }

}
void MainWindow::on_search_list_clicked()
{
    list* point = &stk->get_arr()[stk->search_element(ui->stack->item(ui->stack->currentRow())->text())];
    Set_name sn;
    sn.set_label("Введите имя искомого элемента");
    sn.exec();
    int index = point->search_element(sn.get_name());
    if (index != -1){
        ui->list->setCurrentRow(index);
    }
    else{
        error->set_label("Такого элемента нет");
        error->exec();
    }
}

void MainWindow::delete_all(){
    if (stk->get_size() != 0){
        for(int i = 0; i < stk->get_size(); i++){
            if (stk->get_arr()[i].get_arr() != NULL){
                stk->delete_element();
            }

        }
        delete[] stk->get_arr();
        stk->set_counter(0);
        ui->progress_stack->set_counter(stk->get_counter());
        ui->progress_stack->update();
        ui->stack->clear();
        current_row_prev = -1;
        stk->set_size(0);

    }
}


void MainWindow::on_donload_json_clicked()
{
    QFile json_file;
    QString str;
    json_file.setFileName("C:/Users/123/Desktop/qt/Kursach_up/files/json.save.json");

    json_file.open(QIODevice::ReadOnly | QIODevice::Text);
    str = json_file.readAll();
    json_file.close();

    QJsonDocument json_doc = QJsonDocument::fromJson(str.toUtf8());
    if (json_doc.isEmpty() == true){
        error->set_label("ФАЙЛ БИТЫЙ");
        error->exec();

        return;
    }
    delete_all();

    QJsonArray json_stack = json_doc.array();
    stk->set_size(json_stack[0].toObject().value("size").toInt());
    stk->set_arr();
    for(int i = 1; i < json_stack.size(); i++){
        QJsonObject count = json_stack[i].toObject();

        if(stk->search_element(count.value("name").toString()) != -1){
            error->set_label("В файле присутствует одинаковые элементы(в стеке)");
            error->exec();
            delete_all();
            return;
        }

        stk->input_element(count.value("name").toString());



        list* point;
        point = &stk->get_arr()[i - 1];
        QJsonArray arr_list = count.value("arr").toArray();
        point->set_size(count.value("size").toInt());
        point->set_arr();
        for (int j = 0; j < arr_list.size(); j++){

            if(point->search_element(arr_list[j].toString()) != -1){
                error->set_label("В файле присутствует одинаковые элементы(в cписке) в " + QString::number(i - 1) + " - ячейке");
                error->exec();
                delete_all();
                return;
            }
            point->input_element(arr_list[j].toString());

        }
        ui->progress_stack->set_size(stk->get_size());
        ui->stack->addItem(stk->get_arr()[i - 1].name);
        ui->progress_stack->set_counter(stk->get_counter());
        ui->progress_stack->update();
    }
}

void MainWindow::on_save_json_clicked()
{
    QJsonArray main_arr;
    QJsonObject size_stk;
    size_stk["size"] = stk->get_size();
    main_arr.push_back(size_stk);
    for(int i = 0; i < stk->get_counter(); i++){

       list* point = &stk->get_arr()[i];
       QJsonObject stack_count;
       stack_count["name"] = point->name;
       QJsonArray list_arr;
       for(int j = 0; j < point->get_counter(); j++){
           list_arr.push_back(point->get_arr()[j]);
       }
       stack_count["arr"] = list_arr;
       stack_count["size"] = point->get_size();

       main_arr.push_back(stack_count);
    }
    QFile json_file;
    QJsonDocument doc;
    doc.setArray(main_arr);
    json_file.setFileName("C:/Users/123/Desktop/qt/Kursach_up/files/json.save.json");
    json_file.open(QIODevice::WriteOnly);
    json_file.write(doc.toJson());
    json_file.close();
    error->set_label("Файл сохранен");
    error->exec();


}
