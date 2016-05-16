QT += core
QT += gui
QT += concurrent widgets

CONFIG += c++11

TARGET = QThreads
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cc \
    mythread.cc \
    qtconcurrencytutorial.cc

HEADERS += \
    mythread.hh \
    qtconcurrencytutorial.hh
