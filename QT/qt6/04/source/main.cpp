#include "../include/widget.h"

int main(int ac, char* av[])
{
    QApplication app(ac, av);
    Widget window;
    window.setWindowTitle("Часы в окне");
    window.resize(350, 100);
    window.show();

    return (app.exec());
}
