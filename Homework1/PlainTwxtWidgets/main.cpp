#include "plaintextwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlainTextWidget w;
    w.show();

    return a.exec();
}
