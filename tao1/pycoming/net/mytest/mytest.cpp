#include "mytest.h"
#include "ui_mytest.h"

mytest::mytest(QWidget *parent)
    : QDialog(parent), ui(new Ui::mytest)
{
    ui->setupUi(this);
}

mytest::~mytest()
{
    delete ui;
}
