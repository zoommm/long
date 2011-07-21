#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QDialog>
#include"ui_mydialog.h"

class MyDialog:public QDialog,public Ui_MyDialog
{
    Q_QBJECT
public:
        MyDialog(QWidget *parent = 0);
private slots:
        void enter();
private:
        QString buf;
}
    
#endif
