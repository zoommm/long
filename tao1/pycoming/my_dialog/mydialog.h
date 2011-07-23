#ifndef MYDIALOG_H
#define MYDIALOG_H
#include"ui_mydialog.h"
#include<QDialog>

#include <QtNetwork/QTcpSocket>
#include <QTextStream>
#include <QtNetwork/QHostAddress>
#include <QMessageBox>

namespace Ui
{
    class mydialog;
}

class mydialog : public QDialog,public Ui_mydialog
{
    Q_OBJECT

public:
    mydialog(QWidget *parent = 0);
    ~mydialog();

private:
    Ui::mydialog *ui;
private slots:
        void enter();
        /*add by pycoming 2011-7-23*/
        void sendMsg();
        void recvMsg();
        void error();
private:
          QString buf;
        /*add by pycoming 2011-7-23*/
          QTcpSocket *qtcpSocket;

};

#endif // MYDIALOG_H
