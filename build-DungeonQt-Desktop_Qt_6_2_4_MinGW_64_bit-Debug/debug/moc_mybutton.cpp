/****************************************************************************
** Meta object code from reading C++ file 'mybutton.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DungeonQt/mybutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mybutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mybutton_t {
    const uint offsetsAndSize[22];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_mybutton_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_mybutton_t qt_meta_stringdata_mybutton = {
    {
QT_MOC_LITERAL(0, 8), // "mybutton"
QT_MOC_LITERAL(9, 17), // "onMyButtonClicked"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 6), // "number"
QT_MOC_LITERAL(35, 12), // "startisbegan"
QT_MOC_LITERAL(48, 9), // "savelevel"
QT_MOC_LITERAL(58, 9), // "loadlevel"
QT_MOC_LITERAL(68, 9), // "onClicked"
QT_MOC_LITERAL(78, 9), // "hidestart"
QT_MOC_LITERAL(88, 4), // "save"
QT_MOC_LITERAL(93, 4) // "load"

    },
    "mybutton\0onMyButtonClicked\0\0number\0"
    "startisbegan\0savelevel\0loadlevel\0"
    "onClicked\0hidestart\0save\0load"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mybutton[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,
       5,    1,   68,    2, 0x06,    5 /* Public */,
       6,    0,   71,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   72,    2, 0x08,    8 /* Private */,
       8,    0,   73,    2, 0x08,    9 /* Private */,
       9,    0,   74,    2, 0x08,   10 /* Private */,
      10,    0,   75,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mybutton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mybutton *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onMyButtonClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->startisbegan((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->savelevel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->loadlevel(); break;
        case 4: _t->onClicked(); break;
        case 5: _t->hidestart(); break;
        case 6: _t->save(); break;
        case 7: _t->load(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mybutton::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mybutton::onMyButtonClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (mybutton::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mybutton::startisbegan)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (mybutton::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mybutton::savelevel)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (mybutton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mybutton::loadlevel)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject mybutton::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_mybutton.offsetsAndSize,
    qt_meta_data_mybutton,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_mybutton_t
, QtPrivate::TypeAndForceComplete<mybutton, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *mybutton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mybutton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mybutton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int mybutton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void mybutton::onMyButtonClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mybutton::startisbegan(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mybutton::savelevel(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void mybutton::loadlevel()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
