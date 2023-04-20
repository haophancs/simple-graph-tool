/****************************************************************************
** Meta object code from reading C++ file 'ElementPropertiesTable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/headers/ElementPropertiesTable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ElementPropertiesTable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ElementPropertiesTable_t {
    QByteArrayData data[13];
    char stringdata0[149];
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
QT_MOC_LITERAL(4, 54, 11), // "std::string"
QT_MOC_LITERAL(5, 66, 9), // "node_name"
QT_MOC_LITERAL(6, 76, 14), // "onEdgeSelected"
QT_MOC_LITERAL(7, 91, 5), // "uname"
QT_MOC_LITERAL(8, 97, 5), // "vname"
QT_MOC_LITERAL(9, 103, 12), // "onUnSelected"
QT_MOC_LITERAL(10, 116, 8), // "setGraph"
QT_MOC_LITERAL(11, 125, 17), // "GraphType::Graph*"
QT_MOC_LITERAL(12, 143, 5) // "graph"

    },
    "ElementPropertiesTable\0onGraphChanged\0"
    "\0onNodeSelected\0std::string\0node_name\0"
    "onEdgeSelected\0uname\0vname\0onUnSelected\0"
    "setGraph\0GraphType::Graph*\0graph"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ElementPropertiesTable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,
       6,    2,   43,    2, 0x0a /* Public */,
       9,    0,   48,    2, 0x0a /* Public */,
      10,    1,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void ElementPropertiesTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ElementPropertiesTable *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onGraphChanged(); break;
        case 1: _t->onNodeSelected((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 2: _t->onEdgeSelected((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 3: _t->onUnSelected(); break;
        case 4: _t->setGraph((*reinterpret_cast< GraphType::Graph*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ElementPropertiesTable::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableWidget::staticMetaObject>(),
    qt_meta_stringdata_ElementPropertiesTable.data,
    qt_meta_data_ElementPropertiesTable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
