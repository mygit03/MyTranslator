#-------------------------------------------------
#
# Project created by QtCreator 2016-07-29T19:04:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyTranslator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

TRANSLATIONS+=cn.ts\
              en.ts

RESOURCES += \
    resources.qrc
