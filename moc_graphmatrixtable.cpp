/****************************************************************************
** Meta object code from reading C++ file 'graphmatrixtable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graphmatrixtable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphmatrixtable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphMatrixTable_t {
    QByteArrayData data[10];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphMatrixTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphMatrixTable_t qt_meta_stringdata_GraphMatrixTable = {
    {
QT_MOC_LITERAL(0, 0, 16), // "GraphMatrixTable"
QT_MOC_LITERAL(1, 17, 12), // "graphChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "selectedArc"
QT_MOC_LITERAL(4, 43, 1), // "u"
QT_MOC_LITERAL(5, 45, 1), // "v"
QT_MOC_LITERAL(6, 47, 10), // "adjustCell"
QT_MOC_LITERAL(7, 58, 3), // "row"
QT_MOC_LITERAL(8, 62, 6), // "column"
QT_MOC_LITERAL(9, 69, 10) // "reloadData"

    },
    "GraphMatrixTable\0graphChanged\0\0"
    "selectedArc\0u\0v\0adjustCell\0row\0column\0"
    "reloadData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphMatrixTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    2,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   40,    2, 0x0a /* Public */,
       9,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,

       0        // eod
};

void GraphMatrixTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphMatrixTable *_t = static_cast<GraphMatrixTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->graphChanged(); break;
        case 1: _t->selectedArc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->adjustCell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->reloadData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GraphMatrixTable::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphMatrixTable::graphChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphMatrixTable::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphMatrixTable::selectedArc)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject GraphMatrixTable::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_GraphMatrixTable.data,
      qt_meta_data_GraphMatrixTable,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GraphMatrixTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphMatrixTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphMatrixTable.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int GraphMatrixTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void GraphMatrixTable::graphChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GraphMatrixTable::selectedArc(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
