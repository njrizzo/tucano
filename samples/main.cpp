#include "mesh2img.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mesh2img w;
    w.show();

    return a.exec();
}
