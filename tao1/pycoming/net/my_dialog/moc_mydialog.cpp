/****************************************************************************
** Meta object code from reading C++ file 'mydialog.h'
**
** Created: Fri Jul 22 19:16:22 2011
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mydialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mydialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_mydialog[] = {
    "mydialog\0"
};

const QMetaObject mydialog::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mydialog,
      qt_meta_data_mydialog, 0 }
};

const QMetaObject *mydialog::metaObject() const
{
    return &staticMetaObject;
}

void *mydialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mydialog))
        return static_cast<void*>(const_cast< mydialog*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mydialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE