#-------------------------------------------------
#
# Project created by QtCreator 2020-04-30T12:09:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Thermal_Camera_App
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

SOURCES += main.cpp\
        window.cpp \
    fb.c \
    interpolate.c \
    screenshot.cpp \
    info_window.cpp

HEADERS  += window.h \
    fb.h \
    interpolate.h \
    screenshot.h \
    info_window.h

FORMS    += window.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MLX90640_API/release/ -lMLX90640_API
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MLX90640_API/debug/ -lMLX90640_API
else:unix: LIBS += -L$$OUT_PWD/../MLX90640_API/ -lMLX90640_API

INCLUDEPATH += $$PWD/../MLX90640_API
DEPENDPATH += $$PWD/../MLX90640_API

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MLX90640_API/release/libMLX90640_API.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MLX90640_API/debug/libMLX90640_API.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MLX90640_API/release/MLX90640_API.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MLX90640_API/debug/MLX90640_API.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../MLX90640_API/libMLX90640_API.a

INCLUDEPATH += `pkg-config --cflags opencv`
LIBS += `pkg-config --libs opencv`

# install
target.path = $$[QT_INSTALL_EXAMPLES]/Desktop/screenshot
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS screenshot.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/Desktop/screenshot
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
maemo5: include($$QT_SOURCE_TREE/examples/maemo5pkgrules.pri)
symbian: warning(This example might not fully work on Symbian platform)
maemo5: warning(This example might not fully work on Maemo platform)
simulator: warning(This example might not fully work on Simulator platform)
