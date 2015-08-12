#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <tucano.hpp>
#include <effect.hpp>
#include <phongshader.hpp>
#include <toon.hpp>
#include <utils/qttrackballwidget.hpp>


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
    ~GLWidget();

signals:

public slots:

private:
    QString FileNameMesh;
    QString shader_dir;
    QString FileNameShader;
    Effects::Phong  *phong;
    Effects::Toon   *toon;

};


#endif // GLWIDGET_H
