#ifndef STACK_H
#define STACK_H
#include "list.h"

struct stack{

private:
    list *arr;
    int size = 0;
    int counter = 0;
public:

    void set_arr();
    void set_size(int);
    void set_counter(int);
    list* get_arr();
    int get_size();
    int get_counter();
    bool input_element(QString);
    bool delete_element();
    int search_element(QString);
    bool check_full();
    bool check_empty();
};

#endif // STACK_H
