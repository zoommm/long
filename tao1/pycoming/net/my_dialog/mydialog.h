#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class mydialog;
}

class mydialog : public QMainWindow
{
    Q_OBJECT

public:
    mydialog(QWidget *parent = 0);
    ~mydialog();

private:
    Ui::mydialog *ui;
};

#endif // MYDIALOG_H
