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
        glwidget.cpp \
    normalset.cpp

LIBS += -lGLEW -lGLU

INCLUDEPATH += "../../src"
INCLUDEPATH += "/usr/include/eigen3"
INCLUDEPATH +=  $$TUCANO_PATH/src \
                $$TUCANO_PATH/effects \
                $$EIGEN_PATH

HEADERS  += mainwindow.h \
            glwidget.h \
    normalset.h

FORMS    += mainwindow.ui
HEADERS  += $$TUCANO_PATH/src/utils/qttrackballwidget.hpp


OTHER_FILES += \
        $$TUCANO_PATH/effects/shaders/toonshader.frag \
        $$TUCANO_PATH/effects/shaders/toonshader.vert \
        $$TUCANO_PATH/effects/shaders/ssao.frag \
        $$TUCANO_PATH/effects/shaders/ssao.vert \
        $$TUCANO_PATH/effects/shaders/ssaofinal.frag \
        $$TUCANO_PATH/effects/shaders/ssaofinal.vert \
        $$TUCANO_PATH/effects/shaders/viewspacebuffer.frag \
        $$TUCANO_PATH/effects/shaders/viewspacebuffer.vert \
        $$TUCANO_PATH/effects/shaders/phongshader.frag \
        $$TUCANO_PATH/effects/shaders/phongshader.vert \
        $$TUCANO_PATH/effects/shaders/normalset.vert \
        $$TUCANO_PATH/effects/shaders/normalset.frag
