#-------------------------------------------------
#
# Project created by QtCreator 2015-10-23T22:51:45
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lession
TEMPLATE = app


SOURCES += main.cpp\
        unitlession.cpp \
    testdialog.cpp \
    learndialog.cpp

HEADERS  += unitlession.h \
    testdialog.h \
    learndialog.h

FORMS    += unitlession.ui \
    testdialog.ui \
    learndialog.ui

RESOURCES += \
    icon.qrc
