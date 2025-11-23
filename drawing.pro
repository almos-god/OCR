QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

RC_ICONS=./icon/FlatUiPicture.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
# disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    screenshottool.cpp \
    size_dialog.cpp

HEADERS += \
    QCustomImage.h \
    mainwindow.h \
    screenshottool.h \
    size_dialog.h \
    enum_mappings.h

# Tesseract include path - 指向包含 tesseract 目录的父目录
INCLUDEPATH += ./bin/include

# Tesseract libraries
LIBS += -L$$PWD/bin -ltesseract55

# 或者使用绝对路径更可靠
INCLUDEPATH += $$PWD/bin/include
LIBS += -L$$PWD/bin -ltesseract55

# 删除或注释掉下面这些重复且可能错误的配置：
# win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./release/ -llibtesseract55.dll
# else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./debug/ -llibtesseract55.dll

FORMS += \
    mainwindow.ui \
    size_dialog.ui

RESOURCES += \
    icon/icon.qrc

DEPENDPATH += $$PWD/bin
