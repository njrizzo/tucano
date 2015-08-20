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
TARGET = mesh2img
#
# Take careful when change this
#
APP_NAME    = $$TARGET
HOME_PATH   = $$(HOME)
OSTYPE      = $$(OSTYPE)

isEmpty($$HOME_PATH) {
    warning("The HOME_PATH not set.  This is necessary! Edit a .pro file")
}

isEmpty  ($$OSTYPE) {
    warning(" The OSTYPE enviroment var not was set")
}
#
# PREFIX_PATH   Use this var to setup a prefix to all
# include and lib dir you will need
#
PREFIX_PATH = /usr
#
#  This code below is specific to differents operational systems
#  change olny if you need mor specific
#
freebsd-clang: {# if I use FreeBSD and Clang compiler
                # I must change some local vars by
                # overwrite a PREFIX_PATH
    message(">>>> FreeBSD with Clang Setup")
    PREFIX_PATH = /usr/local
}

macox: {
    message(">>>> Mac OS Setup")
}

linux-g++-64: {
    message( ">>>> Linux 64 Bits with GCC Setup" )
}

linux-clang: {
    message(">>>> Linux with Clang Setup")
}
#
# LOCAL_PATH is the subdir of $HOME change this before
# compile
#
LOCAL_PATH  = Repositorio/GitHub        # <<<<< Must be change
#
# TUCANO_PATH where the tucano lib was found
#
TUCANO_PATH = $$HOME_PATH/$$LOCAL_PATH/tucano
#
# TUCANO_PATH_HEADERS Where the tucano headers was found
#
TUCANO_PATH_HEADERS  = src/utils
#
# EIGEN_PATH Where Eigen lib was found
#
EIGEN_PATH  =  $$PREFIX_PATH/include/eigen3
#
# BUILDDIR Where the executable file was create
#
BUILDDIR = $$TUCANO_PATH/build/$$APP_NAME
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
# If the dirs not exists, I'll create it
#
!exists( $$DESTDIR ) {
    mkpath( $$DESTDIR )
}
!exists( $$OBJECTS_DIR ) {
    mkpath( $$OBJECTS_DIR )
}
!exists( $$MOC_DIR ) {
    mkpath( $$MOC_DIR )
}
!exists( $$RCC_DIR ) {
    mkpath( $$RCC_DIR )
}
!exists( $$UI_DIR ) {
    mkpath( $$UI_DIR )
}
#
# Compile with debug simbols
#
QMAKE_CXXFLAGS += -DTUCANODEBUG \   # Debug on Tucano Library
                    -DDebugON \     # Debug on Code
                    -g              # Debug on Compiler Option
#
# Is Kind of application
#
TEMPLATE = app
#
# Use C++11 Standart
#
CONFIG += c++11
#
# Files sources
#
SOURCES +=  mesh2img.cpp \
            glwidget.cpp \
    main.cpp
#
# HEADERS headers files are we need
HEADERS  += mesh2img.h \
            glwidget.h
#
# Tucano QT integration header
#
HEADERS  += $$TUCANO_PATH/$$TUCANO_PATH_HEADERS/qttrackballwidget.hpp
#
# FORMS Forms we need to build the Application
#
FORMS    += mesh2img.ui
#
# Lib we have use
#
LIBS += -lGLEW -lGLU
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
