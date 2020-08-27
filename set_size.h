#ifndef SET_SIZE_H
#define SET_SIZE_H

#include <QDialog>
#include <QString>

namespace Ui {
class set_size;
}

class set_size : public QDialog
{
    Q_OBJECT

public:
    explicit set_size(QWidget *parent = nullptr);
    ~set_size();

    int get_size();
    void set_label(QString);
    bool get_ok();
    bool get_dont();
private slots:


    void on_buttonBox_accepted();

private:
    int size1 = 0;
    bool ok_dont = false;
    bool dont = true;
    Ui::set_size *ui;
};

#endif // SET_SIZE_H
