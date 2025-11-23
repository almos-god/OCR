/****************************************************************************
** Meta object code from reading C++ file 'apiwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../apiwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apiwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSApiwindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSApiwindowENDCLASS = QtMocHelpers::stringData(
    "Apiwindow",
    "imageGenerated",
    "",
    "pixmap",
    "imageGenerationFailed",
    "errorMessage",
    "imageApiListChanged",
    "apiList",
    "imageApiValidated",
    "isValid",
    "apiKey",
    "chatMessageReceived",
    "message",
    "isUser",
    "chatApiListChanged",
    "chatApiValidated",
    "chatMessageFailed",
    "internetSpeedChanged",
    "speedBytesPerSecond",
    "onImageRequestFinished",
    "QNetworkReply*",
    "reply",
    "onChatRequestFinished",
    "onSpeedTestFinished",
    "onSendButtonClicked",
    "onAddImageApiButtonClicked",
    "onDeleteImageApiButtonClicked",
    "onAddChatApiButtonClicked",
    "onDeleteChatApiButtonClicked",
    "onImageApiLoadButtonClicked",
    "onChatSendButtonClicked",
    "onChatMessageReceived",
    "onDownloadButtonClicked",
    "downloadGeneratedImage",
    "downloadChatMessages",
    "showErrorMessage",
    "updateInternetSpeedDisplay"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSApiwindowENDCLASS_t {
    uint offsetsAndSizes[74];
    char stringdata0[10];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[22];
    char stringdata5[13];
    char stringdata6[20];
    char stringdata7[8];
    char stringdata8[18];
    char stringdata9[8];
    char stringdata10[7];
    char stringdata11[20];
    char stringdata12[8];
    char stringdata13[7];
    char stringdata14[19];
    char stringdata15[17];
    char stringdata16[18];
    char stringdata17[21];
    char stringdata18[20];
    char stringdata19[23];
    char stringdata20[15];
    char stringdata21[6];
    char stringdata22[22];
    char stringdata23[20];
    char stringdata24[20];
    char stringdata25[27];
    char stringdata26[30];
    char stringdata27[26];
    char stringdata28[29];
    char stringdata29[28];
    char stringdata30[24];
    char stringdata31[22];
    char stringdata32[24];
    char stringdata33[23];
    char stringdata34[21];
    char stringdata35[17];
    char stringdata36[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSApiwindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSApiwindowENDCLASS_t qt_meta_stringdata_CLASSApiwindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "Apiwindow"
        QT_MOC_LITERAL(10, 14),  // "imageGenerated"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 6),  // "pixmap"
        QT_MOC_LITERAL(33, 21),  // "imageGenerationFailed"
        QT_MOC_LITERAL(55, 12),  // "errorMessage"
        QT_MOC_LITERAL(68, 19),  // "imageApiListChanged"
        QT_MOC_LITERAL(88, 7),  // "apiList"
        QT_MOC_LITERAL(96, 17),  // "imageApiValidated"
        QT_MOC_LITERAL(114, 7),  // "isValid"
        QT_MOC_LITERAL(122, 6),  // "apiKey"
        QT_MOC_LITERAL(129, 19),  // "chatMessageReceived"
        QT_MOC_LITERAL(149, 7),  // "message"
        QT_MOC_LITERAL(157, 6),  // "isUser"
        QT_MOC_LITERAL(164, 18),  // "chatApiListChanged"
        QT_MOC_LITERAL(183, 16),  // "chatApiValidated"
        QT_MOC_LITERAL(200, 17),  // "chatMessageFailed"
        QT_MOC_LITERAL(218, 20),  // "internetSpeedChanged"
        QT_MOC_LITERAL(239, 19),  // "speedBytesPerSecond"
        QT_MOC_LITERAL(259, 22),  // "onImageRequestFinished"
        QT_MOC_LITERAL(282, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(297, 5),  // "reply"
        QT_MOC_LITERAL(303, 21),  // "onChatRequestFinished"
        QT_MOC_LITERAL(325, 19),  // "onSpeedTestFinished"
        QT_MOC_LITERAL(345, 19),  // "onSendButtonClicked"
        QT_MOC_LITERAL(365, 26),  // "onAddImageApiButtonClicked"
        QT_MOC_LITERAL(392, 29),  // "onDeleteImageApiButtonClicked"
        QT_MOC_LITERAL(422, 25),  // "onAddChatApiButtonClicked"
        QT_MOC_LITERAL(448, 28),  // "onDeleteChatApiButtonClicked"
        QT_MOC_LITERAL(477, 27),  // "onImageApiLoadButtonClicked"
        QT_MOC_LITERAL(505, 23),  // "onChatSendButtonClicked"
        QT_MOC_LITERAL(529, 21),  // "onChatMessageReceived"
        QT_MOC_LITERAL(551, 23),  // "onDownloadButtonClicked"
        QT_MOC_LITERAL(575, 22),  // "downloadGeneratedImage"
        QT_MOC_LITERAL(598, 20),  // "downloadChatMessages"
        QT_MOC_LITERAL(619, 16),  // "showErrorMessage"
        QT_MOC_LITERAL(636, 26)   // "updateInternetSpeedDisplay"
    },
    "Apiwindow",
    "imageGenerated",
    "",
    "pixmap",
    "imageGenerationFailed",
    "errorMessage",
    "imageApiListChanged",
    "apiList",
    "imageApiValidated",
    "isValid",
    "apiKey",
    "chatMessageReceived",
    "message",
    "isUser",
    "chatApiListChanged",
    "chatApiValidated",
    "chatMessageFailed",
    "internetSpeedChanged",
    "speedBytesPerSecond",
    "onImageRequestFinished",
    "QNetworkReply*",
    "reply",
    "onChatRequestFinished",
    "onSpeedTestFinished",
    "onSendButtonClicked",
    "onAddImageApiButtonClicked",
    "onDeleteImageApiButtonClicked",
    "onAddChatApiButtonClicked",
    "onDeleteChatApiButtonClicked",
    "onImageApiLoadButtonClicked",
    "onChatSendButtonClicked",
    "onChatMessageReceived",
    "onDownloadButtonClicked",
    "downloadGeneratedImage",
    "downloadChatMessages",
    "showErrorMessage",
    "updateInternetSpeedDisplay"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSApiwindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  176,    2, 0x06,    1 /* Public */,
       4,    1,  179,    2, 0x06,    3 /* Public */,
       6,    1,  182,    2, 0x06,    5 /* Public */,
       8,    2,  185,    2, 0x06,    7 /* Public */,
      11,    2,  190,    2, 0x06,   10 /* Public */,
      11,    1,  195,    2, 0x26,   13 /* Public | MethodCloned */,
      14,    1,  198,    2, 0x06,   15 /* Public */,
      15,    2,  201,    2, 0x06,   17 /* Public */,
      16,    1,  206,    2, 0x06,   20 /* Public */,
      17,    1,  209,    2, 0x06,   22 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      19,    1,  212,    2, 0x08,   24 /* Private */,
      22,    1,  215,    2, 0x08,   26 /* Private */,
      23,    1,  218,    2, 0x08,   28 /* Private */,
      24,    0,  221,    2, 0x08,   30 /* Private */,
      25,    0,  222,    2, 0x08,   31 /* Private */,
      26,    0,  223,    2, 0x08,   32 /* Private */,
      27,    0,  224,    2, 0x08,   33 /* Private */,
      28,    0,  225,    2, 0x08,   34 /* Private */,
      29,    0,  226,    2, 0x08,   35 /* Private */,
      30,    0,  227,    2, 0x08,   36 /* Private */,
      31,    2,  228,    2, 0x08,   37 /* Private */,
      31,    1,  233,    2, 0x28,   40 /* Private | MethodCloned */,
      32,    0,  236,    2, 0x08,   42 /* Private */,
      33,    0,  237,    2, 0x08,   43 /* Private */,
      34,    0,  238,    2, 0x08,   44 /* Private */,
      35,    1,  239,    2, 0x08,   45 /* Private */,
      36,    0,  242,    2, 0x08,   47 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QStringList,    7,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   12,   13,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QStringList,    7,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::LongLong,   18,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   12,   13,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Apiwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSApiwindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSApiwindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSApiwindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Apiwindow, std::true_type>,
        // method 'imageGenerated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPixmap &, std::false_type>,
        // method 'imageGenerationFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'imageApiListChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QString> &, std::false_type>,
        // method 'imageApiValidated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'chatMessageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'chatMessageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'chatApiListChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QString> &, std::false_type>,
        // method 'chatApiValidated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'chatMessageFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'internetSpeedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'onImageRequestFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'onChatRequestFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'onSpeedTestFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'onSendButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddImageApiButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteImageApiButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddChatApiButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteChatApiButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onImageApiLoadButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onChatSendButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onChatMessageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onChatMessageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onDownloadButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'downloadGeneratedImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'downloadChatMessages'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showErrorMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateInternetSpeedDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Apiwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Apiwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->imageGenerated((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1]))); break;
        case 1: _t->imageGenerationFailed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->imageApiListChanged((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 3: _t->imageApiValidated((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->chatMessageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 5: _t->chatMessageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->chatApiListChanged((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 7: _t->chatApiValidated((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->chatMessageFailed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->internetSpeedChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 10: _t->onImageRequestFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 11: _t->onChatRequestFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 12: _t->onSpeedTestFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 13: _t->onSendButtonClicked(); break;
        case 14: _t->onAddImageApiButtonClicked(); break;
        case 15: _t->onDeleteImageApiButtonClicked(); break;
        case 16: _t->onAddChatApiButtonClicked(); break;
        case 17: _t->onDeleteChatApiButtonClicked(); break;
        case 18: _t->onImageApiLoadButtonClicked(); break;
        case 19: _t->onChatSendButtonClicked(); break;
        case 20: _t->onChatMessageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 21: _t->onChatMessageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->onDownloadButtonClicked(); break;
        case 23: _t->downloadGeneratedImage(); break;
        case 24: _t->downloadChatMessages(); break;
        case 25: _t->showErrorMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 26: _t->updateInternetSpeedDisplay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Apiwindow::*)(const QPixmap & );
            if (_t _q_method = &Apiwindow::imageGenerated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Apiwindow::*)(const QString & );
            if (_t _q_method = &Apiwindow::imageGenerationFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Apiwindow::*)(const QList<QString> & );
            if (_t _q_method = &Apiwindow::imageApiListChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Apiwindow::*)(bool , const QString & );
            if (_t _q_method = &Apiwindow::imageApiValidated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Apiwindow::*)(const QString & , bool );
            if (_t _q_method = &Apiwindow::chatMessageReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Apiwindow::*)(const QList<QString> & );
            if (_t _q_method = &Apiwindow::chatApiListChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Apiwindow::*)(bool , const QString & );
            if (_t _q_method = &Apiwindow::chatApiValidated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Apiwindow::*)(const QString & );
            if (_t _q_method = &Apiwindow::chatMessageFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Apiwindow::*)(qint64 );
            if (_t _q_method = &Apiwindow::internetSpeedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject *Apiwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Apiwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSApiwindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Apiwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void Apiwindow::imageGenerated(const QPixmap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Apiwindow::imageGenerationFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Apiwindow::imageApiListChanged(const QList<QString> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Apiwindow::imageApiValidated(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Apiwindow::chatMessageReceived(const QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 6
void Apiwindow::chatApiListChanged(const QList<QString> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Apiwindow::chatApiValidated(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Apiwindow::chatMessageFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Apiwindow::internetSpeedChanged(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
