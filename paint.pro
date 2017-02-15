#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T20:55:26
#
#-------------------------------------------------

QT       += core gui
QTPLUGIN     += qjpeg
//LIBS +=  qjpeg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintscene.cpp \
    figure.cpp \
    romb.cpp \
    square.cpp \
    triangle.cpp \
    circle.cpp \
    line.cpp \
    colorindicator.cpp \
    colorpalette.cpp \
    rectangle.cpp \
    exception.cpp

HEADERS  += mainwindow.h \
    paintscene.h \
    figure.h \
    romb.h \
    square.h \
    triangle.h \
    circle.h \
    line.h \
    colorindicator.h \
    colorpalette.h \
    rectangle.h \
    exception.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES +=


