/****************************************************************************
** Meta object code from reading C++ file 'ElementPropertiesTable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headers/ElementPropertiesTable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ElementPropertiesTable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ElementPropertiesTable_t {
    QByteArrayData data[9];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ElementPropertiesTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ElementPropertiesTable_t qt_meta_stringdata_ElementPropertiesTable = {
    {
QT_MOC_LITERAL(0, 0, 22), // "ElementPropertiesTable"
QT_MOC_LITERAL(1, 23, 14), // "onGraphChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 14), // "onNodeSelected"
QT_MOC_LITERAL(4, 54, 2), // "id"
QT_MOC_LITERAL(5, 57, 13), // "onArcSelected"
QT_MOC_LITERAL(6, 71, 1), // "u"
QT_MOC_LITERAL(7, 73, 1), // "v"
QT_MOC_LITERAL(8, 75, 12) // "onUnSelected"

    },
    "ElementPropertiesTable\0onGraphChanged\0"
    "\0onNodeSelected\0id\0onArcSelected\0u\0v\0"
    "onUnSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ElementPropertiesTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       5,    2,   38,    2, 0x0a /* Public */,
       8,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,

       0        // eod
};

void ElementPropertiesTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ElementPropertiesTable *_t = static_cast<ElementPropertiesTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onGraphChanged(); break;
        case 1: _t->onNodeSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onArcSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->onUnSelected(); break;
        default: ;
        }
    }
}

const QMetaObject ElementPropertiesTable::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_ElementPropertiesTable.data,
      qt_meta_data_ElementPropertiesTable,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ElementPropertiesTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ElementPropertiesTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ElementPropertiesTable.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int ElementPropertiesTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
