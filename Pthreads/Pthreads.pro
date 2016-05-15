QT += core
QT -= gui

CONFIG += c++11

TARGET = Pthreads
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cc \
    fromtutorialspoint.cc

HEADERS += \
    fromtutorialspoint.hh
