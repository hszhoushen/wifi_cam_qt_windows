#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T12:53:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcp_camera
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
