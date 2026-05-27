#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

void    changeText(QLabel *label)
{
    label->setText("Change text");
}


int main(int argc, char *argv[])
{
    QApplication    app(argc, argv);
    QDialog         *dialog = new QDialog;
    QPushButton     *button = new QPushButton("CHANGE");
    QVBoxLayout     *layout = new QVBoxLayout;
    QLabel          *label  = new QLabel("Hello, World!");

    layout->addWidget(label);
    layout->addWidget(button);
    dialog->setLayout(layout);
    dialog->setWindowTitle("EX03");
    dialog->resize(400, 300);

    QObject::connect(button, &QPushButton::clicked, [&]() { changeText(label); });
    dialog->show();
    return app.exec();
}
