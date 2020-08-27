#ifndef STACK_CONDITION_H
#define STACK_CONDITION_H

#include <QWidget>

namespace Ui {
class Stack_condition;
}

class Stack_condition : public QWidget
{
    Q_OBJECT

public:
    void set_size(int);
    void set_counter(int);
    void update();
    explicit Stack_condition(QWidget *parent = nullptr);
    ~Stack_condition();

private slots:

private:
    int counter = 0,size = 0;
    Ui::Stack_condition *ui;
};

#endif // STACK_CONDITION_H
