#include "mydialog.h"
#include "ui_mydialog.h"
#include<QDialog>

mydialog::mydialog(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::mydialog)
{
    setupUi(this);
    QObject::connect(pushButton,SIGNAL(clicked()),this,SLOT(enter()));
}

mydialog::~mydialog()
{
    delete ui;
}
void mydialog::enter()
{
    buf+=lineEdit->text()+'\n';
    lineEdit->clear();
    textEdit->setText(buf);
    textEdit->moveCursor(QTextCursor::End);
}
