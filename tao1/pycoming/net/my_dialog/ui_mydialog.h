/********************************************************************************
** Form generated from reading ui file 'mydialog.ui'
**
** Created: Fri Jul 22 19:22:57 2011
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mydialog
{
public:
    QWidget *centralWidget;
    QPushButton *Enter;
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mydialog)
    {
        if (mydialog->objectName().isEmpty())
            mydialog->setObjectName(QString::fromUtf8("mydialog"));
        mydialog->resize(600, 400);
        centralWidget = new QWidget(mydialog);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Enter = new QPushButton(centralWidget);
        Enter->setObjectName(QString::fromUtf8("Enter"));
        Enter->setGeometry(QRect(350, 220, 92, 28));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 220, 301, 26));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 20, 411, 192));
        mydialog->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mydialog);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        mydialog->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mydialog);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mydialog->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mydialog);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        mydialog->setStatusBar(statusBar);

        retranslateUi(mydialog);

        QMetaObject::connectSlotsByName(mydialog);
    } // setupUi

    void retranslateUi(QMainWindow *mydialog)
    {
        mydialog->setWindowTitle(QApplication::translate("mydialog", "My dialog", 0, QApplication::UnicodeUTF8));
        Enter->setText(QApplication::translate("mydialog", "Enter", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(mydialog);
    } // retranslateUi

};

namespace Ui {
    class mydialog: public Ui_mydialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
