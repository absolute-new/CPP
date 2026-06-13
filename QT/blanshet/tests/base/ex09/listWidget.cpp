#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication    app(argc, argv);
    QWidget         window;
    window.setWindowTitle("LIST");
    window.resize(400, 300);

    QListWidget     *list = new QListWidget;
    QLabel          *label = new QLabel("Choise: nothing");
    QPushButton     *addButton = new QPushButton("ADD");
    QPushButton     *removeButton = new QPushButton("REMOVE");
    QPushButton     *clearButton = new QPushButton("CLEAR");

    int itemCount = 1;

    QVBoxLayout     *layout = new QVBoxLayout(&window);
    layout->addWidget(list);
    layout->addWidget(label);

    QHBoxLayout     *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(removeButton);
    buttonLayout->addWidget(clearButton);
    layout->addLayout(buttonLayout);

    QObject::connect(list, &QListWidget::currentTextChanged, [&](const QString &text) {
        if (text.isEmpty())
            label->setText("Choise: nothing");
        else
            label->setText("Choice: " + text);
    });

    QObject::connect(addButton, &QPushButton::clicked,[&](){
        list->addItem("Element " + QString::number(itemCount));
        itemCount++;
    });

    QObject::connect(removeButton, &QPushButton::clicked, [&](){
        QListWidgetItem *currentItem = list->currentItem();
        if (currentItem)
            delete currentItem;
    });

    QObject::connect(clearButton, &QPushButton::clicked, [&](){
        list->clear();
        itemCount = 1;
    });
    window.show();

    return app.exec();
}
