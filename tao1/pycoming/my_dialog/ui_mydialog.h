/********************************************************************************
** Form generated from reading ui file 'mydialog.ui'
**
** Created: Sat Jul 23 11:48:19 2011
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
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_mydialog
{
public:
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *mydialog)
    {
        if (mydialog->objectName().isEmpty())
            mydialog->setObjectName(QString::fromUtf8("mydialog"));
        mydialog->resize(414, 307);
        textBrowser = new QTextBrowser(mydialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 50, 371, 241));
        lineEdit = new QLineEdit(mydialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 10, 261, 26));
        pushButton = new QPushButton(mydialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 10, 92, 28));

        retranslateUi(mydialog);

        QMetaObject::connectSlotsByName(mydialog);
    } // setupUi

    void retranslateUi(QDialog *mydialog)
    {
        mydialog->setWindowTitle(QApplication::translate("mydialog", "My  dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("mydialog", "Enter", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(mydialog);
    } // retranslateUi

};

namespace Ui {
    class mydialog: public Ui_mydialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
