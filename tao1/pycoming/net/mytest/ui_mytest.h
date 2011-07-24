/********************************************************************************
** Form generated from reading ui file 'mytest.ui'
**
** Created: Sun Jul 24 15:05:16 2011
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MYTEST_H
#define UI_MYTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QDialog>
#include <QtGui/QFontComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_mytest
{
public:
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QTimeEdit *timeEdit;
    QCalendarWidget *calendarWidget;
    QFontComboBox *fontComboBox;

    void setupUi(QDialog *mytest)
    {
        if (mytest->objectName().isEmpty())
            mytest->setObjectName(QString::fromUtf8("mytest"));
        mytest->resize(600, 400);
        lineEdit = new QLineEdit(mytest);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 40, 181, 26));
        textBrowser = new QTextBrowser(mytest);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 80, 291, 281));
        pushButton = new QPushButton(mytest);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 40, 92, 28));
        timeEdit = new QTimeEdit(mytest);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(350, 20, 131, 51));
        calendarWidget = new QCalendarWidget(mytest);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(350, 80, 241, 271));
        fontComboBox = new QFontComboBox(mytest);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(20, 370, 301, 27));

        retranslateUi(mytest);

        QMetaObject::connectSlotsByName(mytest);
    } // setupUi

    void retranslateUi(QDialog *mytest)
    {
        mytest->setWindowTitle(QApplication::translate("mytest", "mytest", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("mytest", "Enter", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(mytest);
    } // retranslateUi

};

namespace Ui {
    class mytest: public Ui_mytest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTEST_H
