#ifndef FRAME_H
#define FRAME_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class frame;
}

class frame : public QWidget
{
    Q_OBJECT

public:
    explicit frame(QWidget *parent = nullptr);
    ~frame();
    void mouseMoveEvent( QMouseEvent* e );
    void mousePressEvent( QMouseEvent* e );
    void mouseReleaseEvent( QMouseEvent* e );
    void set_title(QString);


private slots:
    void on_exit_clicked();

private:
    Ui::frame *ui;

  //  MainWindow *classM = new MainWindow;
    int dx;
    int dy;
};

#endif // FRAME_H
