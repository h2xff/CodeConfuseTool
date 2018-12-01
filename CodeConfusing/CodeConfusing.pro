#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T22:27:12
#
#-------------------------------------------------

QT       += core gui

#不输出QDebug调试信息
#DEFINES  += QT_NO_WARNING_OUTPUT\
#           QT_NO_DEBUG_OUTPUT
CONFIG   += console
#CONFIG   -= app_bundle
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.10


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CodeConfusing
TEMPLATE = app

OBJECTS_DIR  = tmp
MOC_DIR      = tmp

SOURCES += main.cpp\
        dialog.cpp \
    fileviewer.cpp \
    cppparser.cpp \
    ocparser.cpp \
    srcfilemodel.cpp \
    stringutil.cpp \
    database.cpp \
    classmodel.cpp \
    resultdialog.cpp \
    garbagecode.cpp

HEADERS  += dialog.h \
    fileviewer.h \
    cppparser.h \
    ocparser.h \
    srcfilemodel.h \
    stringutil.h \
    database.h \
    classmodel.h \
    resultdialog.h \
    garbagecode.h

DISTFILES += \
    reskeys.txt \
    garbagepiece.json
