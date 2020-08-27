#include "mainwindow.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFile styleF;

    styleF.setFileName(":/css.css");
    styleF.open(QFile::ReadOnly);
    QString qssSt = styleF.readAll();

    qApp->setStyleSheet(qssSt);

    w.show();
    return a.exec();


}
