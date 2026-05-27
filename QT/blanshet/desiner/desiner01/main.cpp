#include <QApplication>
#include "sortdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Ui::sortDialog *dialog = new Ui::sortDialog;
    dialog->setColumnRange('C', 'F');
    dialog->show();
    return app.exec();
}
