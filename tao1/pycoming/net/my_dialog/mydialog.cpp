#include "mydialog.h"
#include "ui_mydialog.h"

mydialog::mydialog(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::mydialog)
{
    ui->setupUi(this);
}

mydialog::~mydialog()
{
    delete ui;
}
