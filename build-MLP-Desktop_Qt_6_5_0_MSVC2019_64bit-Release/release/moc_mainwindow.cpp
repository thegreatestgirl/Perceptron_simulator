/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MLP/view/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "signal_for_info",
    "",
    "str",
    "slotTimer",
    "on_clear_graphics_view_button_clicked",
    "on_make_a_guess_button_clicked",
    "on_load_network_button_clicked",
    "on_create_network_button_clicked",
    "on_train_net_clicked",
    "on_load_bmp_clicked",
    "on_test_net_clicked",
    "on_save_net_clicked",
    "on_train_on_img_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[10];
    char stringdata5[38];
    char stringdata6[31];
    char stringdata7[31];
    char stringdata8[33];
    char stringdata9[21];
    char stringdata10[20];
    char stringdata11[20];
    char stringdata12[20];
    char stringdata13[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 15),  // "signal_for_info"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 3),  // "str"
        QT_MOC_LITERAL(32, 9),  // "slotTimer"
        QT_MOC_LITERAL(42, 37),  // "on_clear_graphics_view_button..."
        QT_MOC_LITERAL(80, 30),  // "on_make_a_guess_button_clicked"
        QT_MOC_LITERAL(111, 30),  // "on_load_network_button_clicked"
        QT_MOC_LITERAL(142, 32),  // "on_create_network_button_clicked"
        QT_MOC_LITERAL(175, 20),  // "on_train_net_clicked"
        QT_MOC_LITERAL(196, 19),  // "on_load_bmp_clicked"
        QT_MOC_LITERAL(216, 19),  // "on_test_net_clicked"
        QT_MOC_LITERAL(236, 19),  // "on_save_net_clicked"
        QT_MOC_LITERAL(256, 23)   // "on_train_on_img_clicked"
    },
    "MainWindow",
    "signal_for_info",
    "",
    "str",
    "slotTimer",
    "on_clear_graphics_view_button_clicked",
    "on_make_a_guess_button_clicked",
    "on_load_network_button_clicked",
    "on_create_network_button_clicked",
    "on_train_net_clicked",
    "on_load_bmp_clicked",
    "on_test_net_clicked",
    "on_save_net_clicked",
    "on_train_on_img_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   83,    2, 0x08,    3 /* Private */,
       5,    0,   84,    2, 0x08,    4 /* Private */,
       6,    0,   85,    2, 0x08,    5 /* Private */,
       7,    0,   86,    2, 0x08,    6 /* Private */,
       8,    0,   87,    2, 0x08,    7 /* Private */,
       9,    0,   88,    2, 0x08,    8 /* Private */,
      10,    0,   89,    2, 0x08,    9 /* Private */,
      11,    0,   90,    2, 0x08,   10 /* Private */,
      12,    0,   91,    2, 0x08,   11 /* Private */,
      13,    0,   92,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'signal_for_info'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clear_graphics_view_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_make_a_guess_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_load_network_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_create_network_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_train_net_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_load_bmp_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_test_net_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_save_net_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_train_on_img_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_for_info((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->slotTimer(); break;
        case 2: _t->on_clear_graphics_view_button_clicked(); break;
        case 3: _t->on_make_a_guess_button_clicked(); break;
        case 4: _t->on_load_network_button_clicked(); break;
        case 5: _t->on_create_network_button_clicked(); break;
        case 6: _t->on_train_net_clicked(); break;
        case 7: _t->on_load_bmp_clicked(); break;
        case 8: _t->on_test_net_clicked(); break;
        case 9: _t->on_save_net_clicked(); break;
        case 10: _t->on_train_on_img_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (_t _q_method = &MainWindow::signal_for_info; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal_for_info(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
