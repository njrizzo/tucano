#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T15:41:11
#
#-------------------------------------------------

QT       += core gui opengl


TUCANO_PATH = $$PWD/../../

EIGEN_PATH  =  /usr/include/eigen3

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#BUILDDIR = $$TUCANO_PATH/build/samples/rendering/


TARGET = Shadow
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
        glwidget.cpp

LIBS += -lGLEW -lGLU

INCLUDEPATH += "../../src"
INCLUDEPATH += "/usr/include/eigen3"
INCLUDEPATH +=  $$TUCANO_PATH/src $$TUCANO_PATH/effects $$EIGEN_PATH

HEADERS  += mainwindow.h \
            glwidget.h

FORMS    += mainwindow.ui
HEADERS  += $$TUCANO_PATH/src/utils/qttrackballwidget.hpp
