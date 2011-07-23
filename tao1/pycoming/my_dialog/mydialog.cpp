#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDialog>

mydialog::mydialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::mydialog)
{
    setupUi(this);
    qtcpSocket = new QTcpSocket(this);
    /*connect(pushButton,SIGNAL(clicked()),this,SLOT(enter()));
    */
    connect(pushButton,SIGNAL(clicked()),this,SLOT(sendMsg()));
    connect(qtcpSocket,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    qtcpSocket->connectToHost(QHostAddress::LocalHost,8000);

}

mydialog::~mydialog()
{
    delete ui;
}
void mydialog::enter()
{
    buf+=lineEdit->text()+'\n';
    lineEdit->clear();

    textBrowser->setText(buf);
    textBrowser->moveCursor(QTextCursor::End);
}
void mydialog::sendMsg()
{
    QTextStream out(qtcpSocket);
    out<<lineEdit->text()<<endl;
    lineEdit->clear();
}
void mydialog::recvMsg()
{
    if(!qtcpSocket->canReadLine())
    {
        return;
    }
    QString responseLine;
    do
    {
       buf += qtcpSocket->readLine();
    }while(qtcpSocket->canReadLine());

    textBrowser->setText(buf);
    textBrowser->moveCursor(QTextCursor::End);
}
void mydialog::error()
{
    QMessageBox::critical(this,"socket error",qtcpSocket->errorString());
    qtcpSocket->close();
}

