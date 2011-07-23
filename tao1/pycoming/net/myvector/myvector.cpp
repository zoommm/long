#include <QCoreApplication>
#include<QDebug>
int main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);
    QVector<QString> vector(0);
    QVector<QString>:: iterator i;
    vector.append("one");
    vector.append("two");
    vector.append("three");
    /*
    for(int i = 0;i<vector.count();i++)
    {
        qDebug()<<vector[i]<<endl;
    }
    */
    for(int i = vector.begin();i!=vector.end();i++)
    {
        qDebug()<<*i<<endl;
    }
    return a.exec();
}
