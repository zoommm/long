/********************************************************************************
** Form generated from reading ui file 'mydialog.ui'
**
** Created: Fri Jul 22 19:45:52 2011
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
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mydialog
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
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
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 290, 92, 28));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 290, 361, 26));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 20, 461, 251));
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
        pushButton->setText(QApplication::translate("mydialog", "Enter", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(mydialog);
    } // retranslateUi

};

namespace Ui {
    class mydialog: public Ui_mydialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
