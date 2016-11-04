#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T23:26:42
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = PruebaSift
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
INCLUDEPATH += C:\opencv\release\install\include
LIBS += -LC:\opencv\release\install\x64\mingw\bin\

LIBS+= -lopencv_core249 -lopencv_highgui249 -lopencv_imgproc249 -lopencv_features2d249 -lopencv_nonfree249

SOURCES += main.cpp
