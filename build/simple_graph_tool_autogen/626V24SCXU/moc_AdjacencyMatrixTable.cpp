/****************************************************************************
** Meta object code from reading C++ file 'AdjacencyMatrixTable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/headers/AdjacencyMatrixTable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AdjacencyMatrixTable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdjacencyMatrixTable_t {
    QByteArrayData data[11];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdjacencyMatrixTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdjacencyMatrixTable_t qt_meta_stringdata_AdjacencyMatrixTable = {
    {
QT_MOC_LITERAL(0, 0, 20), // "AdjacencyMatrixTable"
QT_MOC_LITERAL(1, 21, 12), // "graphChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 12), // "edgeSelected"
QT_MOC_LITERAL(4, 48, 11), // "std::string"
QT_MOC_LITERAL(5, 60, 5), // "uname"
QT_MOC_LITERAL(6, 66, 5), // "vname"
QT_MOC_LITERAL(7, 72, 10), // "adjustCell"
QT_MOC_LITERAL(8, 83, 3), // "row"
QT_MOC_LITERAL(9, 87, 6), // "column"
QT_MOC_LITERAL(10, 94, 6) // "reload"

    },
    "AdjacencyMatrixTable\0graphChanged\0\0"
    "edgeSelected\0std::string\0uname\0vname\0"
    "adjustCell\0row\0column\0reload"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdjacencyMatrixTable[] = {

 // content:
       8,       // revision
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
       7,    2,   40,    2, 0x0a /* Public */,
      10,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,

       0        // eod
};

void AdjacencyMatrixTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdjacencyMatrixTable *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->graphChanged(); break;
        case 1: _t->edgeSelected((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 2: _t->adjustCell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->reload(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdjacencyMatrixTable::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdjacencyMatrixTable::graphChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdjacencyMatrixTable::*)(std::string , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdjacencyMatrixTable::edgeSelected)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdjacencyMatrixTable::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableWidget::staticMetaObject>(),
    qt_meta_stringdata_AdjacencyMatrixTable.data,
    qt_meta_data_AdjacencyMatrixTable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdjacencyMatrixTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdjacencyMatrixTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdjacencyMatrixTable.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int AdjacencyMatrixTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AdjacencyMatrixTable::graphChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdjacencyMatrixTable::edgeSelected(std::string _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
