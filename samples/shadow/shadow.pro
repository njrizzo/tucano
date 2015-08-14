#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T15:41:11
#
#-------------------------------------------------

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


QT       += core gui opengl
#
# My Application Name
#
TARGET = shadow
#
# Take careful when change this
#
APP_NAME    = $$TARGET
HOME_PATH   = $$(HOME)
#
# LOCAL_PATH is the subdir of $HOME change this before
# compile
#
LOCAL_PATH  = Repositorio/GitHub
#
# TUCANO_PATH where the tucano lib was found
#
TUCANO_PATH = $$HOME_PATH/$$LOCAL_PATH/tucano
#
# EIGEN_PATH Where Eigen lib was found
#
EIGEN_PATH  =  /usr/include/eigen3
#
# BUILDDIR Where the executable file was create
#
BUILDDIR = $$TUCANO_PATH/build/samples/$$APP_NAME
#
# INCLUDEPATH Path where we found all header files
#
INCLUDEPATH +=  $$TUCANO_PATH/src       \
                $$EIGEN_PATH            \
                $$TUCANO_PATH/effects
#
# All Directory of temporary files
#
OBJECTS_DIR =   $$BUILDDIR/obj
MOC_DIR =       $$BUILDDIR/moc
RCC_DIR =       $$BUILDDIR/rcc
UI_DIR =        $$BUILDDIR/ui
DESTDIR =       $$TUCANO_PATH/bin
#
# Compile with debug simbols
#
QMAKE_CXXFLAGS += -DTUCANODEBUG \   # Debug on Tucano Library
                    -DDebugON \     # Debug on Shadow Code
                    -g              # Debug on Compiler Option
#
# Is Kind of application
#
TEMPLATE = app
#
# Use C++11 Standar
#
CONFIG += c++11
#
# Files sources
#
SOURCES +=  main.cpp\
            mainwindow.cpp \
            glwidget.cpp \
            shadow.cpp
#
# HEADERS headers files are we need
HEADERS  += mainwindow.h \
            glwidget.h \
            shadow.h
#
# Tucano QT integration header
#
HEADERS  += $$TUCANO_PATH/src/utils/qttrackballwidget.hpp
#
# FORMS Forms we need to build the Application
#
FORMS    += mainwindow.ui

#
# Lib we have use
#
LIBS += -lGLEW -lGLU -g
#
# OTHER_FILES Other projects files need (shaders)
#
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
        $$TUCANO_PATH/effects/shaders/normalset.frag \
    	  README.txt
