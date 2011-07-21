
#include<QtGui/QApplication>
#include<QtGui/QWidget>
#include<QtGui/QLabel>
//#include<QtGui/QTextCodec>
#include<QtGui/QPushButton>
#include<QtGui/QVBoxLayout>
#include<QtGui>
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    QWidget *p = new QWidget;
    p->setSizeIncrement(100,200);
    QLabel label(p);
    label.setText(QObject::tr("hello lao wang"));
    QPushButton *qb =new QPushButton("&Download",p);
    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(&label);
    layout->addWidget(qb);
    p->setLayout(layout);
    QObject::connect(qb,SIGNAL(clicked()),p,SLOT(close()));
    p->show();
    return app.exec();
}
