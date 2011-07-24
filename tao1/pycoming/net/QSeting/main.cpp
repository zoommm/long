#include <QtCore/QCoreApplication>
#include <QString>
#include <QStringList>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSettings settings("akaedu.org","mysettings");
    QString str("abcdefg");
    QStringList str1;
    str1<<"pycoming"<<"zhangsan"<<"list";
    settings.setValue("string",str);
    settings.setValue("stringlist",str1);
    settings.setValue("int",5);
    settings.setValue("double",3.0);

    QString getstr=settings.value("string").toString();
    QStringList getstr1=settings.value("stringlist").toStringList();
    double getdou=settings.value("double").toDouble();
    int getint=settings.value("int").toInt();

    qDebug()<<getstr<<getstr1<<getdou<<getint;


    return a.exec();

}
