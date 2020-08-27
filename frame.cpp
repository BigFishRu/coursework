#include "frame.h"
#include "ui_frame.h"
#include <QMouseEvent>
frame::frame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frame)
{
    ui->setupUi(this);
    QPixmap *p = new QPixmap(":/image/jojo.BHHtF.jpg");
    ui->label_2->setPixmap(*p);
}

frame::~frame()
{
    delete ui;
}

void frame::mouseMoveEvent( QMouseEvent* e ) {
    if( e->buttons() | Qt::LeftButton ) {
        //int x = 0,y = 0;
      //  x = e->pos().x()- dx +this->parentWidget()->geometry().left() - this->geometry().left();
        //y = e->pos().x()- dy + this->parentWidget()->geometry().top() - this->geometry().top();
        if(this->parentWidget()->isWindow() == true){
        this->parentWidget()->move(e->globalX() - dx, e->globalY() - dy);
        }
        else this->parentWidget()->parentWidget()->move(e->globalX() - dx, e->globalY() - dy);

     }
}

void frame::mousePressEvent( QMouseEvent* e ) {
    if( e->button() == Qt::LeftButton ) {
        dx = e->x();
        dy = e->y();
        setCursor( Qt::OpenHandCursor );
    }
}

void frame::mouseReleaseEvent( QMouseEvent* e ) {
    if( e->button() == Qt::LeftButton ) {
        setCursor( Qt::ArrowCursor );
    }
}


void frame::on_exit_clicked()
{
    if (this->parentWidget()->isWindow() == true){
            this->parentWidget()->close();
    }
    else this->parentWidget()->parentWidget()->close();
}
void frame::set_title(QString str){
    ui->label->setText(str);
}
