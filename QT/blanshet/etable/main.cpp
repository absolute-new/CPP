#include "ETable.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ETable window;
    window.show();

    return app.exec();
}
