#include "../include/widget.h"
#include <QApplication>

int main(int ac, char *av[])
{
    QApplication app(ac, av);
    Widget window;
    window.setWindowTitle("Назначение клавиш быстрого доступа");
    window.resize(350, 150);
    window.show();
    return app.exec();
}
