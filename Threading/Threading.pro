QT += core
QT -= gui

CONFIG += c++11

TARGET = Threading
CONFIG += console
CONFIG -= app_bundle
CONFIG += C++11

TEMPLATE = app

SOURCES += main.cc \
    solariantutorial.cc \
    tutorialscup.cc

HEADERS += \
    solariantutorial.hh \
    tutorialscup.hh
