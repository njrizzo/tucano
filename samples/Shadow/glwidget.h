#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QWidget>


class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent=0);
    void initialize(void);
    void setMeshFile(QString fn);

    ~GLWidget();

signals:

public slots:
};


#endif // GLWIDGET_H
