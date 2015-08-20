#ifndef MESH2IMG_H
#define MESH2IMG_H

#include <QMainWindow>

#include "glwidget.h"

namespace Ui {
class mesh2img;
}

class mesh2img : public QMainWindow
{
    Q_OBJECT

public:
    explicit mesh2img(QWidget *parent = 0);
    ~mesh2img();

    void createCanvas(void);
    void createMenu(void);
    void createActions(void);

    QString FileName;
    QString sampleDir = "../sample/models/";

    GLWidget  *glwidget;

public slots:

    void QuitApp(void);
    void OpenFile(void);
    void OpenFileShader(void);
    void ViewReset(void);
    void CloseFile(void);
    void SaveAs(void);
    void AboutMe(void);
    void AboutQT(void);
    void AboutTucano(void);



private:
    Ui::mesh2img *ui;

    QAction *actionOpen;
    QAction *actionOpenShader;
    QAction *actionSave_as;
    QAction *actionClose;
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionAbout_QT;
    QAction *actionAbout_Tucano;
    QAction *actionViewReset;

    QMenu   *fileMenu;
    QMenu   *viewMenu;
    QMenu   *helpMenu;

};

#endif // MESH2IMG_H
