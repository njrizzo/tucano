#include "mesh2img.h"
#include "ui_mesh2img.h"

#include <QMessageBox>

mesh2img::mesh2img(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mesh2img)
{
    ui->setupUi(this);
    createCanvas();
    createActions();
    createMenu();
}

mesh2img::~mesh2img()
{
    delete ui;
}

void mesh2img::createCanvas(void){

    glwidget = new GLWidget(this->ui->MainFrame);
    glwidget->resize(this->ui->MainFrame->width(), this->ui->MainFrame->height());
    glwidget->show();
    glwidget->adjustSize();
    glwidget->initialize();

}

void mesh2img::createMenu(void){
     fileMenu = new QMenu(tr("&File"), this);
     fileMenu->addAction(actionOpen);
     fileMenu->addAction(actionOpenShader);
     fileMenu->addAction(actionSave_as);
     fileMenu->addAction(actionClose);
     fileMenu->addSeparator();
     fileMenu->addAction(actionQuit);

     viewMenu = new QMenu(tr("&View"), this);
     viewMenu->addAction(actionViewReset);

     helpMenu = new QMenu(tr("&Help"), this);
     helpMenu->addAction(actionAbout);
     helpMenu->addAction(actionAbout_QT);
     helpMenu->addAction(actionAbout_Tucano);

     menuBar()->addMenu(fileMenu);
     menuBar()->addMenu(viewMenu);
     menuBar()->addMenu(helpMenu);

}

void mesh2img::createActions(void){

    actionOpen          = new QAction(tr("&Open Mesh"   ), this);
    actionOpenShader    = new QAction(tr("Open Shade&r" ), this);
    actionSave_as       = new QAction(tr("&Save As ..." ), this);
    actionClose         = new QAction(tr("Close &Mesh"  ), this);
    actionAbout         = new QAction(tr("About Me"     ), this);
    actionAbout_QT      = new QAction(tr("About QT"     ), this);
    actionAbout_Tucano  = new QAction(tr("About Tucano" ), this);
    actionQuit          = new QAction(tr("E&xit"        ), this);
    actionViewReset     = new QAction(tr("Reset view"   ), this);

    actionOpen->setShortcut(tr("Ctrl+O"));
    actionOpenShader->setShortcut(tr("Ctrl+R"));
    actionQuit->setShortcut(tr("Ctrl+X"));
    actionSave_as->setShortcut(tr("Ctrl+S"));
    actionClose->setShortcut(tr("Ctrl+M"));
    actionAbout->setShortcut(tr("Ctrl+Shift+A"));
    actionAbout_QT->setShortcut(tr("Ctrl+Shift+B"));
    actionAbout_Tucano->setShortcut(tr("Ctrl+Shift+C"));

    connect(actionOpen,         SIGNAL(triggered()), this, SLOT(OpenFile())         );
    connect(actionOpenShader,   SIGNAL(triggered()), this, SLOT(OpenFileShader())   );
    connect(actionSave_as,      SIGNAL(triggered()), this, SLOT(SaveAs())           );
    connect(actionClose,        SIGNAL(triggered()), this, SLOT(CloseFile())        );
    connect(actionQuit,         SIGNAL(triggered()), this, SLOT(QuitApp())          );
    connect(actionAbout,        SIGNAL(triggered()), this, SLOT(AboutMe())          );
    connect(actionAbout_QT,     SIGNAL(triggered()), this, SLOT(AboutQT())          );
    connect(actionAbout_Tucano, SIGNAL(triggered()), this, SLOT(AboutTucano())      );
    connect(actionViewReset,    SIGNAL(triggered()), this, SLOT(ViewReset())        );

}

void mesh2img::QuitApp(void) {
    qApp->quit();
}

void mesh2img::OpenFile(void){
    QFileDialog     *fd;
    QString         filter;

      fd = new QFileDialog();
      fd->setDirectory(sampleDir);
      FileName = fd->getOpenFileName(this,tr("Open Mesh Files"),sampleDir,"Mesh Files ( *.ply)", &filter);
      if (!FileName.isEmpty()){
        glwidget->setMeshFile(FileName);
        glwidget->loadMesh();
      }

}

void mesh2img::OpenFileShader(void){
    QFileDialog     *fd;
    QString         filter;

      fd = new QFileDialog();
      fd->setDirectory(sampleDir);
      FileName = fd->getOpenFileName(this,tr("Open Shader Files"),sampleDir,"Shader Files ( *.vert | *.frag)", &filter);
      fd->hide();

      if (!FileName.isEmpty()){
        glwidget->setShaderFile(FileName);
        glwidget->loadShader();
      }

}

void mesh2img::ViewReset(void){
    glwidget->resetView();
}

void mesh2img::CloseFile(void){
    glwidget->closeMesh();

}

void mesh2img::SaveAs(){

}

void mesh2img::AboutMe(){

}

void mesh2img::AboutQT(){
    qApp->aboutQt();
}

void mesh2img::AboutTucano(void){
    QMessageBox::about(this, tr("About Shadow"),
               tr("<p><H2>Tucano</H2> Is Library for rapid prototyping with modern OpenGL and GLSL.<BR>"
                  "<P>Tucano encapsulates many common OpenGL/GLSL features in C++ classes, saving a"
                  "lot of coding and allowing the developer to concentrate on the core of the "
                  "application and the Shader codes.<BR>"
                  "<A HREF=https://github.com/LCG-UFRJ/tucano>Tucano Web Site</A>"));
}
