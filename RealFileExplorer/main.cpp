#include "RealFileExplorer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RealFileExplorer w;
    w.show();
    return a.exec();
}
