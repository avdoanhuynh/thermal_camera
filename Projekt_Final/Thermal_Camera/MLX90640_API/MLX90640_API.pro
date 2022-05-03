#-------------------------------------------------
#
# Project created by QtCreator 2020-04-30T11:58:49
#
#-------------------------------------------------

QT       -= core gui

TARGET = MLX90640_API
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

SOURCES += \
    MLX90640_API.cpp \
    MLX90640_LINUX_I2C_Driver.cpp

HEADERS += \
    MLX90640_API.h \
    MLX90640_I2C_Driver.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
