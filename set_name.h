#ifndef SET_NAME_H
#define SET_NAME_H

#include <QDialog>
#include <QString>

namespace Ui {
class Set_name;
}

class Set_name : public QDialog
{
    Q_OBJECT

public:
    explicit Set_name(QWidget *parent = nullptr);
    ~Set_name();
    QString get_name();
    void set_label(QString);
    bool get_ok();
private slots:


    void on_buttonBox_accepted();

private:
    QString name;
    bool ok_dont = false;
    Ui::Set_name *ui;
};

#endif // SET_NAME_H
