/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "setFreq"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 1), // "b"
QT_MOC_LITERAL(4, 22, 11), // "showGoodbye"
QT_MOC_LITERAL(5, 34, 5), // "close"
QT_MOC_LITERAL(6, 40, 9), // "showTask1"
QT_MOC_LITERAL(7, 50, 9), // "showPatch"
QT_MOC_LITERAL(8, 60, 9), // "showTask2"
QT_MOC_LITERAL(9, 70, 6), // "showQ1"
QT_MOC_LITERAL(10, 77, 10), // "q1Response"
QT_MOC_LITERAL(11, 88, 10), // "showQ1Next"
QT_MOC_LITERAL(12, 99, 6), // "showQ3"
QT_MOC_LITERAL(13, 106, 6), // "showQ4"
QT_MOC_LITERAL(14, 113, 15), // "updateOffer_yes"
QT_MOC_LITERAL(15, 129, 14), // "updateOffer_no"
QT_MOC_LITERAL(16, 144, 7), // "showWTA"
QT_MOC_LITERAL(17, 152, 8) // "conclude"

    },
    "MainWindow\0setFreq\0\0b\0showGoodbye\0"
    "close\0showTask1\0showPatch\0showTask2\0"
    "showQ1\0q1Response\0showQ1Next\0showQ3\0"
    "showQ4\0updateOffer_yes\0updateOffer_no\0"
    "showWTA\0conclude"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x0a /* Public */,
       4,    1,   92,    2, 0x0a /* Public */,
       5,    1,   95,    2, 0x0a /* Public */,
       6,    1,   98,    2, 0x0a /* Public */,
       7,    1,  101,    2, 0x0a /* Public */,
       8,    1,  104,    2, 0x0a /* Public */,
       9,    1,  107,    2, 0x0a /* Public */,
      10,    1,  110,    2, 0x0a /* Public */,
      11,    1,  113,    2, 0x0a /* Public */,
      12,    1,  116,    2, 0x0a /* Public */,
      13,    1,  119,    2, 0x0a /* Public */,
      14,    1,  122,    2, 0x0a /* Public */,
      15,    1,  125,    2, 0x0a /* Public */,
      16,    0,  128,    2, 0x0a /* Public */,
      17,    0,  129,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setFreq((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->showGoodbye((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->close((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->showTask1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->showPatch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->showTask2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->showQ1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->q1Response((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->showQ1Next((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->showQ3((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->showQ4((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->updateOffer_yes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->updateOffer_no((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->showWTA(); break;
        case 14: _t->conclude(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
