#include "tucano.hpp"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createCanvas();
    createActions();
    createMenu();
//    initApplication();
    Tucano::QtTrackballWidget::initialize();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createCanvas(){

    glwidget = new GLWidget(this);

    glwidget->initialize();
    glwidget->show();
    glwidget->adjustSize();
}

void MainWindow::createMenu(void){
     fileMenu = new QMenu(tr("&File"), this);
     fileMenu->addAction(actionOpen);
     fileMenu->addAction(actionSave_as);
     fileMenu->addAction(actionClose);
     fileMenu->addSeparator();
     fileMenu->addAction(actionQuit);

     viewMenu = new QMenu(tr("&View"), this);

     helpMenu = new QMenu(tr("&Help"), this);
     helpMenu->addAction(actionAbout);
     helpMenu->addAction(actionAbout_QT);
     helpMenu->addAction(actionAbout_Tucano);

     menuBar()->addMenu(fileMenu);
     menuBar()->addMenu(viewMenu);
     menuBar()->addMenu(helpMenu);

}

void MainWindow::createActions(){

    actionOpen          = new QAction(tr("&Open Mesh"   ), this);
    actionSave_as       = new QAction(tr("&Save As ..." ), this);
    actionClose         = new QAction(tr("Close &Mesh"  ), this);
    actionAbout         = new QAction(tr("About Me"     ), this);
    actionAbout_QT      = new QAction(tr("About QT"     ), this);
    actionAbout_Tucano  = new QAction(tr("About Tucano" ), this);
    actionQuit          = new QAction(tr("E&xit"        ), this);

    actionOpen->setShortcut(tr("Ctrl+O"));
    actionQuit->setShortcut(tr("Ctrl+X"));
    actionSave_as->setShortcut(tr("Ctrl+S"));
    actionClose->setShortcut(tr("Ctrl+M"));
    actionAbout->setShortcut(tr("Ctrl+Shift+A"));
    actionAbout_QT->setShortcut(tr("Ctrl+Shift+B"));
    actionAbout_Tucano->setShortcut(tr("Ctrl+Shift+C"));

    connect(actionOpen,         SIGNAL(triggered()), this, SLOT(OpenFile())     );
    connect(actionSave_as,      SIGNAL(triggered()), this, SLOT(SaveAs())       );
    connect(actionClose,        SIGNAL(triggered()), this, SLOT(CloseFile())    );
    connect(actionQuit,         SIGNAL(triggered()), this, SLOT(QuitApp())      );
    connect(actionAbout,        SIGNAL(triggered()), this, SLOT(AboutMe())      );
    connect(actionAbout_QT,     SIGNAL(triggered()), this, SLOT(AboutQT())      );
    connect(actionAbout_Tucano, SIGNAL(triggered()), this, SLOT(AboutTucano())  );
}

void MainWindow::QuitApp(void) {
    qApp->quit();
}

void MainWindow::OpenFile(void){
    QFileDialog     *fd;
    QString         filter;

      fd = new QFileDialog();
      fd->setDirectory(sampleDir);
      FileName = fd->getOpenFileName(this,tr("Open Mesh Files"),sampleDir,"Mesh Files ( *.ply)", &filter);
      if (!FileName.isEmpty()){
        glwidget->setMeshFile(FileName);
        glwidget->initialize();
      }

}

void MainWindow::CloseFile(void){

}

void MainWindow::SaveAs(){

}

void MainWindow::AboutMe(){

}

void MainWindow::AboutQT(){
    qApp->aboutQt();
}

void MainWindow::AboutTucano(void){
    QMessageBox::about(this, tr("About Shadow"),
               tr("<p><H2>Tucano</H2> Is Library for rapid prototyping with modern OpenGL and GLSL.<BR>"
                  "<P>Tucano encapsulates many common OpenGL/GLSL features in C++ classes, saving a"
                  "lot of coding and allowing the developer to concentrate on the core of the "
                  "application and the Shader codes.<BR>"
                  "<A HREF=https://github.com/LCG-UFRJ/tucano>Tucano Web Site</A>"));
}
