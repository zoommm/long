#ifndef MYTEST_H
#define MYTEST_H

#include <QtGui/QDialog>

namespace Ui
{
    class mytest;
}

class mytest : public QDialog
{
    Q_OBJECT

public:
    mytest(QWidget *parent = 0);
    ~mytest();

private:
    Ui::mytest *ui;
};

#endif // MYTEST_H
