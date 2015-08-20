#include "glwidget.h"
#include <QtGlobal>

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#   include <QGLWidget>
#else
#   include <QtOpenGL/QGLWidget>
#endif

#include <QWidget>
#include <tucano.hpp>

#ifdef __FreeBSD__
#   define SHADER_DIR "/home2/rizzo/Repositorio/GitHub/tucano/effects/shaders/"
#else
#   define SHADER_DIR "/lcg/home/rizzo/Repositorio/GitHub/tucano/effects/shaders/"
#endif

GLWidget::GLWidget(QWidget *parent): Tucano::QtTrackballWidget(parent){

}

GLWidget::~GLWidget(){

}

void GLWidget::paintGL(void){

}

void GLWidget::initialize(void){

}

void GLWidget::setMeshFile(QString fn){}
void GLWidget::setShaderFile(QString fn){}
void GLWidget::resetView(void){}
bool GLWidget::loadMesh(void){}
bool GLWidget::loadShader(void){}
bool GLWidget::closeMesh(void){}

