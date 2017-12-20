#-------------------------------------------------
#
# Project created by QtCreator 2017-12-18T17:22:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fixture
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ventanaerror.cpp \
    ventanaok.cpp

HEADERS  += mainwindow.h \
    ventanaerror.h \
    ventanaok.h

FORMS    += mainwindow.ui \
    ventanaerror.ui \
    ventanaok.ui

RESOURCES += \
    imagen1.qrc \
    imagen.qrc \
    imagen2.qrc

DISTFILES += \
    ../../ok.png
