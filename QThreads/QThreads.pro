QT += core
QT -= gui

CONFIG += c++11

TARGET = QThreads
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cc \
    mythread.cc

HEADERS += \
    mythread.hh
