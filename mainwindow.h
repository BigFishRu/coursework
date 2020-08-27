#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"
#include "stack_condition.h"
#include <QTime>
#include <QTimer>
#include "dialog.h"
#include "frame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int get_dx();
    int get_dy();
    void set_dx(int);
    void set_dy(int);
    void delete_all();

private slots:
    void on_input_stack_clicked();

    void on_delete_stack_clicked();

    void on_search_stack_clicked();

    void update_list_widget();
    void on_input_list_clicked();

    void on_delete_list_clicked();

    void on_search_list_clicked();


    void on_donload_json_clicked();

    void on_save_json_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Dialog *error = new Dialog;
    int current_row_prev = -1;
    stack* stk = new stack;
    int dx;
    int dy;

};
#endif // MAINWINDOW_H
