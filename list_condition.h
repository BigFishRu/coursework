#ifndef LIST_CONDITION_H
#define LIST_CONDITION_H

#include <QWidget>

namespace Ui {
class List_condition;
}

class List_condition : public QWidget
{
    Q_OBJECT

public:
    void set_size(int);
    void set_counter(int);
    void update();
    explicit List_condition(QWidget *parent = nullptr);
    ~List_condition();

private:
    int counter = 0,size = 0;
    Ui::List_condition *ui;
};

#endif // LIST_CONDITION_H
