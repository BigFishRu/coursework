#include "list.h"
#include <iostream>
#include <QListWidgetItem>
void list::set_size(int x){
    size = x;
}

void list::set_arr(){
    arr = new QString[size];
}
QString* list::get_arr(){
    return arr;
}
int list::get_size(){
    return size;
}
int list::get_counter(){
    return counter;
}
bool list::check_full(){
    if (counter == size){
        return true;
    }
    else return false;
}
bool list::check_empty(){
    if(counter == 0){
        return true;
    }
    else return false;
}
bool list::input_element(QString str){
    if (check_full() != true){
        arr[counter] = str;
        counter++;
        return true;
    }
    else return false;
}
QListWidgetItem* list::input_up(QString str, int x){
    int i = size - 1;
            while (i != x) {
                arr[i] = arr[i - 1];
                arr[i - 1] = "";
                i--;
            }
            arr[x] = str;
            counter++;
            QListWidgetItem* l = new QListWidgetItem(arr[x]);
            return l;
}
QListWidgetItem* list::input_down(QString str, int x){
     int i = size - 1;
     while (i != x + 1) {
         arr[i] = arr[i - 1];
         arr[i - 1] = "";
         i--;
         }
         arr[x + 1] = str;
         counter++;
         QListWidgetItem* l = new QListWidgetItem(arr[x + 1]);
         return l;
}
void list::delete_element(int x){
    arr[x] = "";
    counter -- ;
}
int list::search_element(QString str){
    for (int index = counter - 1; index != -1; index--){
        if(arr[index] == str){
            return index;
        }
    }
    return -1;
}
list::~list(){
    if (size != 0){
    delete[] arr;
    arr = NULL;
    }
}
