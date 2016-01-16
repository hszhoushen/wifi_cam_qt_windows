#-------------------------------------------------
#
# Project created by QtCreator 2016-01-08T14:56:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    thread.cpp \
    tcp.cpp

HEADERS  += mainwindow.h \
    thread.h \
    tcp.h

FORMS    += mainwindow.ui

HEADERS += \
    ../winsock2.h

LIBS +=  \
../WS2_32.Lib
