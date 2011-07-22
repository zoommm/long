#ifndef MYDIALOG_H
#define MYDIALOG_H
#include<QDialog>

#include "ui_mydialog.h"

#include <QtGui/QMainWindow>

namespace Ui
{
    class mydialog;
}

class mydialog : public QMainWindow,public Ui_mydialog
{
    Q_OBJECT;

public:
    mydialog(QWidget *parent = 0);
    ~mydialog();

private:
    Ui::mydialog *ui;
private slots:
            void enter();
private:
             QString buf;
};

#endif // MYDIALOG_H
