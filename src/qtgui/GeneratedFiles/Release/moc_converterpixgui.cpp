/****************************************************************************
** Meta object code from reading C++ file 'converterpixgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "prerequisites_gui.h"
#include "../../converterpixgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'converterpixgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConverterPIXGUI_t {
    QByteArrayData data[12];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConverterPIXGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConverterPIXGUI_t qt_meta_stringdata_ConverterPIXGUI = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ConverterPIXGUI"
QT_MOC_LITERAL(1, 16, 14), // "ufsListClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 49, 24), // "ufsListCurrentRowChanged"
QT_MOC_LITERAL(5, 74, 13), // "ufsAddClicked"
QT_MOC_LITERAL(6, 88, 17), // "ufsUnmountClicked"
QT_MOC_LITERAL(7, 106, 12), // "ufsUpClicked"
QT_MOC_LITERAL(8, 119, 14), // "ufsDownClicked"
QT_MOC_LITERAL(9, 134, 20), // "exportPathBtnClicked"
QT_MOC_LITERAL(10, 155, 16), // "exportPathEdited"
QT_MOC_LITERAL(11, 172, 14) // "convertClicked"

    },
    "ConverterPIXGUI\0ufsListClicked\0\0"
    "QListWidgetItem*\0ufsListCurrentRowChanged\0"
    "ufsAddClicked\0ufsUnmountClicked\0"
    "ufsUpClicked\0ufsDownClicked\0"
    "exportPathBtnClicked\0exportPathEdited\0"
    "convertClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConverterPIXGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       5,    0,   65,    2, 0x08 /* Private */,
       6,    0,   66,    2, 0x08 /* Private */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConverterPIXGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConverterPIXGUI *_t = static_cast<ConverterPIXGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ufsListClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->ufsListCurrentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ufsAddClicked(); break;
        case 3: _t->ufsUnmountClicked(); break;
        case 4: _t->ufsUpClicked(); break;
        case 5: _t->ufsDownClicked(); break;
        case 6: _t->exportPathBtnClicked(); break;
        case 7: _t->exportPathEdited(); break;
        case 8: _t->convertClicked(); break;
        default: ;
        }
    }
}

const QMetaObject ConverterPIXGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ConverterPIXGUI.data,
      qt_meta_data_ConverterPIXGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConverterPIXGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConverterPIXGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConverterPIXGUI.stringdata0))
        return static_cast<void*>(const_cast< ConverterPIXGUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ConverterPIXGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
