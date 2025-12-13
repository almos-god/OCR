QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

# 链接std::filesystem所需的库
LIBS += -lstdc++fs

# 禁用特定的编译器警告
QMAKE_CXXFLAGS += -Wno-int-in-bool-context

RC_ICONS=./icon/FlatUiPicture.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
# disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    QCustomImage.cpp \
    mainwindow.cpp \
    screenshottool.cpp \
    size_dialog.cpp \
    language_selection_dialog.cpp

HEADERS += \
    QCustomImage.h \
    mainwindow.h \
    screenshottool.h \
    size_dialog.h \
    enum_mappings.h \
    language_selection_dialog.h

# Tesseract include path - 指向包含 tesseract 目录的父目录
INCLUDEPATH += ./bin/include

# Tesseract libraries
LIBS += -L$$PWD/bin -ltesseract55

# 添加Windows DWM API库引用
win32:LIBS += -lDwmapi

# 或者使用绝对路径更可靠
INCLUDEPATH += $$PWD/bin/include
LIBS += -L$$PWD/bin -ltesseract55

# 添加OpenCV配置
# OpenCV头文件路径 - 包含所有模块的头文件路径
INCLUDEPATH += D:/opencv/sources/include
INCLUDEPATH += D:/opencv/sources/modules/core/include
INCLUDEPATH += D:/opencv/sources/modules/imgproc/include
INCLUDEPATH += D:/opencv/sources/modules/highgui/include
INCLUDEPATH += D:/opencv/sources/modules/imgcodecs/include
INCLUDEPATH += D:/opencv/sources/modules/videoio/include
INCLUDEPATH += D:/opencv/build_mingw

# OpenCV库文件路径
LIBS += -L D:/opencv/build_mingw/lib

# OpenCV库文件
LIBS += -lopencv_core460 -lopencv_imgproc460 -lopencv_highgui460

# Windows平台下，将OpenCV的dll文件复制到输出目录
win32:CONFIG(release, debug|release): {
    QMAKE_POST_LINK += $$quote(cmd /c copy /Y "D:\opencv\build_mingw\bin\libopencv_core460.dll" "$$OUT_PWD\\")
    QMAKE_POST_LINK += $$quote( && copy /Y "D:\opencv\build_mingw\bin\libopencv_imgproc460.dll" "$$OUT_PWD\\")
    QMAKE_POST_LINK += $$quote( && copy /Y "D:\opencv\build_mingw\bin\libopencv_highgui460.dll" "$$OUT_PWD\\")
} else:win32:CONFIG(debug, debug|release): {
    QMAKE_POST_LINK += $$quote(cmd /c copy /Y "D:\opencv\build_mingw\bin\libopencv_core460.dll" "$$OUT_PWD\\")
    QMAKE_POST_LINK += $$quote( && copy /Y "D:\opencv\build_mingw\bin\libopencv_imgproc460.dll" "$$OUT_PWD\\")
    QMAKE_POST_LINK += $$quote( && copy /Y "D:\opencv\build_mingw\bin\libopencv_highgui460.dll" "$$OUT_PWD\\")
}

FORMS += \
    mainwindow.ui \
    size_dialog.ui

RESOURCES += \
    icon/icon.qrc

DEPENDPATH += $$PWD/bin
