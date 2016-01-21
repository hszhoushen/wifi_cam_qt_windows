#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T22:16:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpCamera
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcp.cpp \
    thread.cpp

HEADERS  += mainwindow.h \
    tcp.h \
    thread.h \
    log.h

HEADERS += \
    ../winsock2.h

LIBS +=  \
../WS2_32.Lib

FORMS    += mainwindow.ui
