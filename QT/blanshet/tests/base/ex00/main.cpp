#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication    app(argc, argv);
    QDialog         *dialog = new QDialog;

    dialog->setWindowTitle("My firs window");
    dialog->resize(400, 300);
    dialog->show();
    return app.exec();
}
