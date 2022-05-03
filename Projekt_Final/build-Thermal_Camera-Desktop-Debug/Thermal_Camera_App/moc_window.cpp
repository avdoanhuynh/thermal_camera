/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Thermal_Camera/Thermal_Camera_App/window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Window[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,   29,   36,   36, 0x0a,
      37,   59,   36,   36, 0x0a,
      66,   88,   36,   36, 0x0a,
      95,   88,   36,   36, 0x0a,
     121,   36,   36,   36, 0x0a,
     134,   36,   36,   36, 0x0a,
     149,   36,   36,   36, 0x0a,
     162,   36,   36,   36, 0x0a,
     181,   36,   36,   36, 0x0a,
     199,  226,   36,   36, 0x0a,
     232,   36,   36,   36, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Window[] = {
    "Window\0changeDisplayMax(int)\0tempe1\0"
    "\0changeDisplayMin(int)\0tempe5\0"
    "changeZoomFactor(int)\0factor\0"
    "changeRotationFactor(int)\0changeUnit()\0"
    "freezePushed()\0savePushed()\0"
    "changeInfoPushed()\0detectionPushed()\0"
    "detectionSliderChange(int)\0value\0"
    "shutDownPushed()\0"
};

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Window *_t = static_cast<Window *>(_o);
        switch (_id) {
        case 0: _t->changeDisplayMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeDisplayMin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeZoomFactor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeRotationFactor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeUnit(); break;
        case 5: _t->freezePushed(); break;
        case 6: _t->savePushed(); break;
        case 7: _t->changeInfoPushed(); break;
        case 8: _t->detectionPushed(); break;
        case 9: _t->detectionSliderChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->shutDownPushed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Window::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Window,
      qt_meta_data_Window, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Window::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Window))
        return static_cast<void*>(const_cast< Window*>(this));
    return QWidget::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
