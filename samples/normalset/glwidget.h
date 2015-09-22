#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <tucano.hpp>
#include <effect.hpp>
#include <phongshader.hpp>
#include <toon.hpp>
#include <utils/qttrackballwidget.hpp>

#include "normalset.h"


class GLWidget : public Tucano::QtTrackballWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent=0);
    void initialize();//int x, int y, int w, int h);
    void setMeshFile(QString fn);
    void setShaderFile(QString fn);
    void paintGL(void);
    void resetView(void);
    bool loadMesh(void);
    bool loadShader(void);
    bool closeMesh(void);
    void setEyesNormal(bool checked);
    void setLightNormal(bool checked);
    void setCossenoEnable(bool checked);
    void setGooshEffect(bool checked);
    void setHatchedEffect(bool checked);
    ~GLWidget();

signals:

public slots:

private:
    QString FileNameMesh;
    QString shader_dir;
    QString FileNameShader;
    Effects::Phong  *phong;
    Effects::Toon   *toon;
    Effects::NormalSet  *normal;
    bool    eyesnormal;
    bool    lightnormal;
    bool    hatchedenable;

};


#endif // GLWIDGET_H
