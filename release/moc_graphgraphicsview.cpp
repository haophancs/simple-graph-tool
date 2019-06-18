/****************************************************************************
** Meta object code from reading C++ file 'graphgraphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graphgraphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphgraphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphGraphicsView_t {
    QByteArrayData data[21];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphGraphicsView_t qt_meta_stringdata_GraphGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 17), // "GraphGraphicsView"
QT_MOC_LITERAL(1, 18, 8), // "unSelect"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "selectedNode"
QT_MOC_LITERAL(4, 41, 2), // "id"
QT_MOC_LITERAL(5, 44, 11), // "selectedArc"
QT_MOC_LITERAL(6, 56, 1), // "u"
QT_MOC_LITERAL(7, 58, 1), // "v"
QT_MOC_LITERAL(8, 60, 10), // "addNewNode"
QT_MOC_LITERAL(9, 71, 10), // "newNodePos"
QT_MOC_LITERAL(10, 82, 10), // "removeNode"
QT_MOC_LITERAL(11, 93, 8), // "editNode"
QT_MOC_LITERAL(12, 102, 11), // "isolateNode"
QT_MOC_LITERAL(13, 114, 10), // "addArcFrom"
QT_MOC_LITERAL(14, 125, 14), // "startAlgorithm"
QT_MOC_LITERAL(15, 140, 4), // "algo"
QT_MOC_LITERAL(16, 145, 9), // "removeArc"
QT_MOC_LITERAL(17, 155, 9), // "addNewArc"
QT_MOC_LITERAL(18, 165, 6), // "setArc"
QT_MOC_LITERAL(19, 172, 11), // "needRefresh"
QT_MOC_LITERAL(20, 184, 6) // "redraw"

    },
    "GraphGraphicsView\0unSelect\0\0selectedNode\0"
    "id\0selectedArc\0u\0v\0addNewNode\0newNodePos\0"
    "removeNode\0editNode\0isolateNode\0"
    "addArcFrom\0startAlgorithm\0algo\0removeArc\0"
    "addNewArc\0setArc\0needRefresh\0redraw"
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
       5,    2,   88,    2, 0x06 /* Public */,
       8,    1,   93,    2, 0x06 /* Public */,
      10,    1,   96,    2, 0x06 /* Public */,
      11,    1,   99,    2, 0x06 /* Public */,
      12,    1,  102,    2, 0x06 /* Public */,
      13,    1,  105,    2, 0x06 /* Public */,
      14,    2,  108,    2, 0x06 /* Public */,
      16,    2,  113,    2, 0x06 /* Public */,
      17,    0,  118,    2, 0x06 /* Public */,
      18,    2,  119,    2, 0x06 /* Public */,
      19,    0,  124,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::QPointF,    9,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   15,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void GraphGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphGraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->unSelect(); break;
        case 1: _t->selectedNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->selectedArc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->addNewNode((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->removeNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->editNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->isolateNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->addArcFrom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->startAlgorithm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->removeArc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->addNewArc(); break;
        case 11: _t->setArc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->needRefresh(); break;
        case 13: _t->redraw(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GraphGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::unSelect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::selectedNode)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::selectedArc)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::addNewNode)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::removeNode)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::editNode)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::isolateNode)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::addArcFrom)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::startAlgorithm)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::removeArc)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::addNewArc)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsView::setArc)) {
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
    &QGraphicsView::staticMetaObject,
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
void GraphGraphicsView::unSelect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GraphGraphicsView::selectedNode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphGraphicsView::selectedArc(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphGraphicsView::addNewNode(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphGraphicsView::removeNode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GraphGraphicsView::editNode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GraphGraphicsView::isolateNode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GraphGraphicsView::addArcFrom(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GraphGraphicsView::startAlgorithm(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GraphGraphicsView::removeArc(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GraphGraphicsView::addNewArc()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void GraphGraphicsView::setArc(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void GraphGraphicsView::needRefresh()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
