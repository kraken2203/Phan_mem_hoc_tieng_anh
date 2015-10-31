#include "unitlession.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    unitlession w;
    w.resize(1200,600);
    w.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    w.show();

    return a.exec();
}
