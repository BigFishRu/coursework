#include "stack.h"

void stack::set_arr(){
    arr = new list[size];
}
void stack::set_size(int x){
    size = x;
}
void stack::set_counter(int x){
    counter = x;
}
list* stack::get_arr(){
    return arr;
}
int stack::get_size(){
    return size;
}
int stack::get_counter(){
    return counter;
}
bool stack::check_full(){
    if (counter == size){
        return true;
    }
    else return false;
}
bool stack::check_empty(){
    if(counter == 0){
        return true;
    }
    else return false;
}
bool stack::input_element(QString str){
    if (check_full() != true){
        list* point = new list;
        point->name = str;
        arr[counter] = *point;
        counter++;
        return true;
    }
    else return false;
}
bool stack::delete_element(){
    if(check_empty() != true){
        counter--;
        arr[counter].~list();


        return true;
    }
    else return false;
}
int stack::search_element(QString str){
    for (int index = 0; index != counter; index++){
        if(arr[index].name == str){
            return index;
        }
    }
    return -1;
}
