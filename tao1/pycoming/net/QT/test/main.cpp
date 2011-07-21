#include"mydialog.h"
#include <QApplication>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv)
    MyDialog d;
    d.show();
    return app.exec();
}
