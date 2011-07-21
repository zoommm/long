#include"mydialog.h"

MyDialog::MyDialog(QWidget *parent)
:QDialog(parent)
{
    setupUi(this);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(enteri()));

}
void MyDialog::enter()
{
    buf+= lineEdit->text()+'\n';
    lineEdit->clear();
    textBrowser->setText(buf);
    textBrowser->moveCursor(QTextCursor::End);
}
