#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication    app(argc, argv);

    QWidget         window;
    window.setWindowTitle("Line edit");
    window.resize(300, 200);

    QLineEdit       *nameEdit = new QLineEdit;
    nameEdit->setPlaceholderText("Enter you name");

    QPushButton     *greetButton = new QPushButton("Say hello");
    QLabel          *label = new QLabel("");
    label->setAlignment(Qt::AlignCenter);

    QVBoxLayout     *layout = new QVBoxLayout(&window);
    layout->addWidget(nameEdit);
    layout->addWidget(greetButton);
    layout->addWidget(label);

    QObject::connect(greetButton, &QPushButton::clicked, [&]() {
        QString name = nameEdit->text();
        if (!name.isEmpty())
            label->setText("Hello, " + name + "!.");
        else
            label->setText("Enter you name!");
    } );
    window.show();
    return app.exec();
}
