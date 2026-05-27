#include <QApplication>
#include "finddialog.hpp"

int main(int argc, char *argv[])
{
    QApplication    app(argc, argv);
    FindDialog      *dialog = new FindDialog;
    dialog->show();
    return app.exec();
}
