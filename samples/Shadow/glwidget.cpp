#include "glwidget.h"
#include <QOpenGLWidget>
#include <QWidget>

GLWidget::GLWidget(QWidget *parent){

}

void GLWidget::initialize(void){

    makeCurrent();
    glColor3f(0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

}

void GLWidget::setMeshFile(QString fn){

}

GLWidget::~GLWidget(){

}

void GLWidget::paintGL(void){
    glColor3f(0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

}

