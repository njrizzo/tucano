#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    GLWidget    *glwidget;

private:
    Ui::MainWindow *ui;
    void createMenu(void);
    void createCanvas(void);
    void createActions(void);
    void initApplication(void);
    QString FileName;
    QString sampleDir = "../sample/models/";


public slots:

    void OpenFile(void);
    void CloseFile(void);
    void QuitApp(void);
    void SaveAs(void);
    void AboutMe(void);
    void AboutQT(void);
    void AboutTucano(void);

signals:


private:
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionClose;
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionAbout_QT;
    QAction *actionAbout_Tucano;

    QMenu   *fileMenu;
    QMenu   *viewMenu;
    QMenu   *helpMenu;



};

#endif // MAINWINDOW_H
