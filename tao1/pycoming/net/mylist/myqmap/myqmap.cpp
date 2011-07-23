#include <QCoreApplication>
#include<QDebug>
#include <QMap>
int main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);
    QMap<QString,QString> map;
    map.insert("beijing","111");
    map.insert("shanghai","021");
    map.insert("tianjing","022");
    map.insert("chongqing","0222");
    map.insert("changchun","0431");
    QMap<QString,QString>::const_iterator i;
    for(i = map.constBegin();i!=map.constEnd();++i)
    {
        qDebug()<<i.key()<<" "<<i.value();
    }
    QMap<QString,QString>::iterator mi;
    mi = map.find("chongqing");
    if(mi!=map.end())
    {
        mi.value()="043200";
    }
    QMap<QString,QString>::const_iterator modi;
    qDebug()<<"";

    for(modi = map.constBegin();modi!=map.constEnd();++modi)
    {
        qDebug()<<modi.key()<<" "<<modi.value();
    }
    return a.exec();
}
