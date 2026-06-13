#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication    app(argc, argv);
    QMainWindow     *window = new QMainWindow;
    QPushButton     *button = new QPushButton("Press me");

    button->setParent(window);

    QObject::connect(button, &QPushButton::clicked, [](){ qDebug() << "Hello World!"; });


    window->resize(500, 500);
    window->show();

    return app.exec();
}
