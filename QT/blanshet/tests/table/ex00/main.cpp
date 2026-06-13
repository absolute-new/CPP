#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QMessageBox>

int main(int ac, char *av[])
{
    QApplication app(ac, av);
    QWidget window;
    window.setWindowTitle("Contact list");
    window.resize(400, 300);

    QListWidget *list = new QListWidget;
    QPushButton *addButton = new QPushButton("ADD");
    QPushButton *deleteButton = new QPushButton("DELETE");
    QPushButton *clearButton = new QPushButton("CLEAR");

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(list);
    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    layout->addWidget(clearButton);

    QObject::connect(addButton, &QPushButton::clicked, [&](){
        QDialog dialog(&window);
        dialog.setWindowTitle("New contact");
        dialog.resize(300, 100);

        QVBoxLayout *dialogLayout = new QVBoxLayout(&dialog);
        QLineEdit *nameEdit = new QLineEdit;
        nameEdit->setPlaceholderText("Enter name");
        QDialogButtonBox *buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        dialogLayout->addWidget(nameEdit);
        dialogLayout->addWidget(buttonBox);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

        if (dialog.exec() == QDialog::Accepted)
        {
            QString name = nameEdit->text();
            if (!name.isEmpty())
                list->addItem(name);
        }
    });

    QObject::connect(deleteButton, &QPushButton::clicked, [&](){
        QListWidgetItem *item = list->currentItem();
        if (item)
            delete item;
        else
            QMessageBox::information(&window, "War", "Take contact for delete");
    });

    QObject::connect(clearButton, &QPushButton::clicked, [&](){
        list->clear();
    });

    window.show();

    return app.exec();
}
