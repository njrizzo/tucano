#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void createMenu(void);
    void createActions(void);

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
