#include "../include/widget.h"

int main(int ac, char* av[])
{
    QApplication app(ac, av);
    Widget window;
    window.setWindowTitle("Назначение обработчиков сигналов");
    window.resize(350, 120);
    window.show();

    return (app.exec());
}
