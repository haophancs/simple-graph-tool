/****************************************************************************
** Meta object code from reading C++ file 'GraphGraphicsView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../graphics/headers/GraphGraphicsView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphGraphicsView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphGraphicsView_t {
    QByteArrayData data[25];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphGraphicsView_t qt_meta_stringdata_GraphGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 17), // "GraphGraphicsView"
QT_MOC_LITERAL(1, 18, 10), // "unSelected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "nodeSelected"
QT_MOC_LITERAL(4, 43, 11), // "std::string"
QT_MOC_LITERAL(5, 55, 9), // "node_name"
QT_MOC_LITERAL(6, 65, 9), // "nodeAdded"
QT_MOC_LITERAL(7, 75, 3), // "pos"
QT_MOC_LITERAL(8, 79, 11), // "auto_naming"
QT_MOC_LITERAL(9, 91, 11), // "nodeRemoved"
QT_MOC_LITERAL(10, 103, 10), // "nodeEdited"
QT_MOC_LITERAL(11, 114, 12), // "nodeIsolated"
QT_MOC_LITERAL(12, 127, 13), // "edgeAddedFrom"
QT_MOC_LITERAL(13, 141, 14), // "startAlgorithm"
QT_MOC_LITERAL(14, 156, 13), // "StartAlgoFlag"
QT_MOC_LITERAL(15, 170, 9), // "algo_flag"
QT_MOC_LITERAL(16, 180, 11), // "source_name"
QT_MOC_LITERAL(17, 192, 12), // "edgeSelected"
QT_MOC_LITERAL(18, 205, 5), // "uname"
QT_MOC_LITERAL(19, 211, 5), // "vname"
QT_MOC_LITERAL(20, 217, 11), // "edgeRemoved"
QT_MOC_LITERAL(21, 229, 9), // "edgeAdded"
QT_MOC_LITERAL(22, 239, 7), // "edgeSet"
QT_MOC_LITERAL(23, 247, 11), // "needRefresh"
QT_MOC_LITERAL(24, 259, 6) // "redraw"

    },
    "GraphGraphicsView\0unSelected\0\0"
    "nodeSelected\0std::string\0node_name\0"
    "nodeAdded\0pos\0auto_naming\0nodeRemoved\0"
    "nodeEdited\0nodeIsolated\0edgeAddedFrom\0"
    "startAlgorithm\0StartAlgoFlag\0algo_flag\0"
    "source_name\0edgeSelected\0uname\0vname\0"
    "edgeRemoved\0edgeAdded\0edgeSet\0needRefresh\0"
    "redraw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphGraphicsView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,
       6,    2,   88,    2, 0x06 /* Public */,
       9,    1,   93,    2, 0x06 /* Public */,
      10,    1,   96,    2, 0x06 /* Public */,
      11,    1,   99,    2, 0x06 /* Public */,
      12,    1,  102,    2, 0x06 /* Public */,
      13,    2,  105,    2, 0x06 /* Public */,
      17,    2,  110,    2, 0x06 /* Public */,
      20,    2,  115,    2, 0x06 /* Public */,
      21,    0,  120,    2, 0x06 /* Public */,
      22,    2,  121,    2, 0x06 /* Public */,
      23,    0,  126,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      24,    0,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Bool,    7,    8,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 4,   15,   16,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,   18,   19,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,   18,   19,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,   18,   19,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void GraphGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphGraphicsView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->unSelected(); break;
        case 1: _t->nodeSelected((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->nodeAdded((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->nodeRemoved((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->nodeEdited((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 5: _t->nodeIsolated((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 6: _t->edgeAddedFrom((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 7: _t->startAlgorithm((*reinterpret_cast< StartAlgoFlag(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 8: _t->edgeSelected((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 9: _t->edgeRemoved((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 10: _t->edgeAdded(); break;
        case 11: _t->edgeSet((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 12: _t->needRefresh(); break;
        case 13: _t->redraw(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GraphGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::unSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::nodeSelected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(QPointF , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::nodeAdded)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::nodeRemoved)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::nodeEdited)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::nodeIsolated)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::edgeAddedFrom)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(StartAlgoFlag , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::startAlgorithm)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(std::string , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::edgeSelected)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(std::string , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::edgeRemoved)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::edgeAdded)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(std::string , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::edgeSet)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::needRefresh)) {
                *result = 12;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GraphGraphicsView::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_GraphGraphicsView.data,
    qt_meta_data_GraphGraphicsView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GraphGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphGraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int GraphGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void GraphGraphicsView::unSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GraphGraphicsView::nodeSelected(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphGraphicsView::nodeAdded(QPointF _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphGraphicsView::nodeRemoved(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphGraphicsView::nodeEdited(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GraphGraphicsView::nodeIsolated(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GraphGraphicsView::edgeAddedFrom(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GraphGraphicsView::startAlgorithm(StartAlgoFlag _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GraphGraphicsView::edgeSelected(std::string _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GraphGraphicsView::edgeRemoved(std::string _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GraphGraphicsView::edgeAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void GraphGraphicsView::edgeSet(std::string _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void GraphGraphicsView::needRefresh()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
