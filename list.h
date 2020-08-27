#ifndef LIST_H
#define LIST_H
#include <QString>
#include <QListWidgetItem>

struct list{
private:
    QString* arr ;
    int size = 0;
    int counter  = 0;
public:
    ~list();
    QString name;
    void set_size(int);
    void set_arr();
    QString* get_arr();
    int get_size();
    int get_counter();
    bool input_element(QString);
    QListWidgetItem* input_up(QString, int);
    QListWidgetItem* input_down(QString, int);
    void delete_element(int);
    bool search_element();
    bool check_full();
    bool check_empty();
    int search_element(QString);

};


#endif // LIST_H
