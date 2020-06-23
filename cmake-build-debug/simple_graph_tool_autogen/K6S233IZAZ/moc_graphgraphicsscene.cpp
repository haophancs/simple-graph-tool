/****************************************************************************
** Meta object code from reading C++ file 'graphgraphicsscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headers/graphgraphicsscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphgraphicsscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphGraphicsScene_t {
    QByteArrayData data[14];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphGraphicsScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphGraphicsScene_t qt_meta_stringdata_GraphGraphicsScene = {
    {
QT_MOC_LITERAL(0, 0, 18), // "GraphGraphicsScene"
QT_MOC_LITERAL(1, 19, 12), // "graphChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "needRedraw"
QT_MOC_LITERAL(4, 44, 10), // "reloadData"
QT_MOC_LITERAL(5, 55, 13), // "demoAlgorithm"
QT_MOC_LITERAL(6, 69, 30), // "std::list<std::pair<int,int> >"
QT_MOC_LITERAL(7, 100, 16), // "listOfPairToDemo"
QT_MOC_LITERAL(8, 117, 13), // "GraphDemoFlag"
QT_MOC_LITERAL(9, 131, 4), // "flag"
QT_MOC_LITERAL(10, 136, 14), // "std::list<int>"
QT_MOC_LITERAL(11, 151, 15), // "listOfNumToDemo"
QT_MOC_LITERAL(12, 167, 26), // "std::list<std::list<int> >"
QT_MOC_LITERAL(13, 194, 16) // "listOfListToDemo"

    },
    "GraphGraphicsScene\0graphChanged\0\0"
    "needRedraw\0reloadData\0demoAlgorithm\0"
    "std::list<std::pair<int,int> >\0"
    "listOfPairToDemo\0GraphDemoFlag\0flag\0"
    "std::list<int>\0listOfNumToDemo\0"
    "std::list<std::list<int> >\0listOfListToDemo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphGraphicsScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x0a /* Public */,
       5,    2,   47,    2, 0x0a /* Public */,
       5,    2,   52,    2, 0x0a /* Public */,
       5,    2,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 8,   11,    9,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 8,   13,    9,

       0        // eod
};

void GraphGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphGraphicsScene *_t = static_cast<GraphGraphicsScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->graphChanged(); break;
        case 1: _t->needRedraw(); break;
        case 2: _t->reloadData(); break;
        case 3: _t->demoAlgorithm((*reinterpret_cast< std::list<std::pair<int,int> >(*)>(_a[1])),(*reinterpret_cast< GraphDemoFlag(*)>(_a[2]))); break;
        case 4: _t->demoAlgorithm((*reinterpret_cast< const std::list<int>(*)>(_a[1])),(*reinterpret_cast< GraphDemoFlag(*)>(_a[2]))); break;
        case 5: _t->demoAlgorithm((*reinterpret_cast< const std::list<std::list<int> >(*)>(_a[1])),(*reinterpret_cast< GraphDemoFlag(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GraphGraphicsScene::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsScene::graphChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphGraphicsScene::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsScene::needRedraw)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject GraphGraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_GraphGraphicsScene.data,
      qt_meta_data_GraphGraphicsScene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GraphGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphGraphicsScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int GraphGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GraphGraphicsScene::graphChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GraphGraphicsScene::needRedraw()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
