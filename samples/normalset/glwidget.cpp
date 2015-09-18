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

void GLWidget::initialize(void ) {

    Tucano::QtTrackballWidget::initialize();
    shader_dir = SHADER_DIR;
//    phong = new Effects::Phong();
//    phong->setShadersDir(shader_dir.toStdString());
//    phong->initialize();

//    toon = new Effects::Toon();
//    toon->setShadersDir(shader_dir.toStdString());
//    toon->initialize();

    normal = new Effects::NormalSet();
    normal->setShadersDir(shader_dir.toStdString());
    normal->initialize();
    normal->setEyesNormal(false);
    normal->setLightNormal(false);
    normal->setCossenoEnable(false);
    normal->setGooshEffect(false);


}

void GLWidget::resetView(void){

}

void GLWidget::setMeshFile(QString fn){
    FileNameMesh = fn;

}

bool GLWidget::loadMesh(){
    openMesh(FileNameMesh.toStdString());
    return true;
}

void GLWidget::setShaderFile(QString fn){
    FileNameShader = fn;

}

bool GLWidget::loadShader(){
    //this->phong->load(FileNameShader);
    return true;
}

bool GLWidget::closeMesh(void){
    mesh.reset();
    return true;
}

GLWidget::~GLWidget(){

}

void GLWidget::paintGL(void){
    makeCurrent();

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    phong->render(mesh, camera, light_trackball);
//    toon->render(mesh, camera, light_trackball);
    normal->render(mesh, camera,light_trackball);
    glEnable(GL_DEPTH_TEST);
    camera.render();

}

void GLWidget::setEyesNormal(bool checked){
    normal->setEyesNormal(checked);
}

void GLWidget::setLightNormal(bool checked){
    normal->setLightNormal(checked);
}

void GLWidget::setCossenoEnable(bool checked){
    normal->setCossenoEnable(checked);
}

void GLWidget::setGooshEffect(bool checked){
    normal->setGooshEffect(checked);
}
