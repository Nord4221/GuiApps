#include "SideCalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SideCalculator w;
    w.show();

    return a.exec();
}
