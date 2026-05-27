#include <QApplication>
#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication    app(argc, argv);
    QDialog         *dialog = new QDialog;
    QPushButton     *button = new QPushButton("CLOSE");
    QHBoxLayout     *layout = new QHBoxLayout;

    dialog->setWindowTitle("Program");
    dialog->resize(400, 300);
    layout->addWidget(button);
    dialog->setLayout(layout);

    QObject::connect(button, &QPushButton::clicked, dialog, &QDialog::close);
    dialog->show();
    return app.exec();
}
