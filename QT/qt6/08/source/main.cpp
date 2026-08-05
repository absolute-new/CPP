#include "../include/widget.h"
#include <QApplication>

int main(int ac, char *av[])
{
    QApplication app(ac, av);
    Widget window;
    window.setWindowTitle("Изменение положения окна и его размеров");
    window.resize(350, 100);
    window.show();

    return app.exec();
}
