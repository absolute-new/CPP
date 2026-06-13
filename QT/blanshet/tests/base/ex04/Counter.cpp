#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication    app(argc, argv);

    QWidget         window;
    window.setWindowTitle("Counter");
    window.resize(300, 250);

    QLabel          *label = new QLabel("0");
    QFont           font;

    font = label->font();
    font.setPointSize(24);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);

    QPushButton     *plusButton = new QPushButton("Plus (+1)");
    QPushButton     *minusButton = new QPushButton("Minus (-1)");
    QPushButton     *resetButton = new QPushButton("Reset");

    QVBoxLayout     *layout = new QVBoxLayout(&window);
    layout->addWidget(label);
    layout->addWidget(plusButton);
    layout->addWidget(minusButton);
    layout->addWidget(resetButton);

    int counter = 0;

    QObject::connect(plusButton, &QPushButton::clicked, [&]() { counter++; label->setText(QString::number(counter)); });
    QObject::connect(minusButton, &QPushButton::clicked, [&]() { counter--; label->setText(QString::number(counter)); });
    QObject::connect(resetButton, &QPushButton::clicked, [&]() { counter = 0; label->setText(QString::number(counter)); });

    window.show();

    return app.exec();
}
