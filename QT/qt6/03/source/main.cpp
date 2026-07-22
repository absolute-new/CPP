#include "../include/widget.h"

int main(int ac, char* av[])
{
    QApplication app(ac, av);
    Widget window;
    window.setWindowTitle("Генерация сигнала из программы");
    window.resize(350, 150);
    window.show();

    return(app.exec());
}
