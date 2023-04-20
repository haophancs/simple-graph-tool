/****************************************************************************
** Meta object code from reading C++ file 'GraphGraphicsScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../graphics/headers/GraphGraphicsScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphGraphicsScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphGraphicsScene_t {
    QByteArrayData data[16];
    char stringdata0[261];
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
QT_MOC_LITERAL(4, 44, 6), // "reload"
QT_MOC_LITERAL(5, 51, 11), // "setInterval"
QT_MOC_LITERAL(6, 63, 8), // "interval"
QT_MOC_LITERAL(7, 72, 13), // "demoAlgorithm"
QT_MOC_LITERAL(8, 86, 46), // "std::list<std::pair<std::stri..."
QT_MOC_LITERAL(9, 133, 16), // "listOfPairToDemo"
QT_MOC_LITERAL(10, 150, 13), // "GraphDemoFlag"
QT_MOC_LITERAL(11, 164, 4), // "flag"
QT_MOC_LITERAL(12, 169, 22), // "std::list<std::string>"
QT_MOC_LITERAL(13, 192, 16), // "listOfNodeToDemo"
QT_MOC_LITERAL(14, 209, 34), // "std::list<std::list<std::stri..."
QT_MOC_LITERAL(15, 244, 16) // "listOfListToDemo"

    },
    "GraphGraphicsScene\0graphChanged\0\0"
    "needRedraw\0reload\0setInterval\0interval\0"
    "demoAlgorithm\0"
    "std::list<std::pair<std::string,std::string> >\0"
    "listOfPairToDemo\0GraphDemoFlag\0flag\0"
    "std::list<std::string>\0listOfNodeToDemo\0"
    "std::list<std::list<std::string> >\0"
    "listOfListToDemo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphGraphicsScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       7,    2,   55,    2, 0x0a /* Public */,
       7,    2,   60,    2, 0x0a /* Public */,
       7,    2,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 10,   13,   11,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 10,   15,   11,

       0        // eod
};

void GraphGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphGraphicsScene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->graphChanged(); break;
        case 1: _t->needRedraw(); break;
        case 2: _t->reload(); break;
        case 3: _t->setInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->demoAlgorithm((*reinterpret_cast< const std::list<std::pair<std::string,std::string> >(*)>(_a[1])),(*reinterpret_cast< GraphDemoFlag(*)>(_a[2]))); break;
        case 5: _t->demoAlgorithm((*reinterpret_cast< const std::list<std::string>(*)>(_a[1])),(*reinterpret_cast< GraphDemoFlag(*)>(_a[2]))); break;
        case 6: _t->demoAlgorithm((*reinterpret_cast< const std::list<std::list<std::string> >(*)>(_a[1])),(*reinterpret_cast< GraphDemoFlag(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GraphGraphicsScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsScene::graphChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GraphGraphicsScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphGraphicsScene::needRedraw)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GraphGraphicsScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_GraphGraphicsScene.data,
    qt_meta_data_GraphGraphicsScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
