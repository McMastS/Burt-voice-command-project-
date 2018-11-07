#include "burtwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    burtWindow w;
    w.show();

    return a.exec();
}
