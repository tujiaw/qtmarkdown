#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T16:07:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webenginewidgets

TARGET = qtmarkdown
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    webengineview.cpp \
    webpage.cpp \
    webchannel.cpp \
    json.cpp

HEADERS  += mainwindow.h \
    webengineview.h \
    webpage.h \
    webchannel.h \
    json.h

FORMS    += mainwindow.ui

RESOURCES += \
    rc.qrc
