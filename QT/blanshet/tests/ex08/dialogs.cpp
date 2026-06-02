#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication    app(argc, argv);
    QWidget         window;
    QPushButton     *button = new QPushButton("ENTRY");
    window.setWindowTitle("MAIN");
    window.resize(300, 200);

    QVBoxLayout     *layout = new QVBoxLayout(&window);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [&](){
        QDialog     dialog(&window);
        dialog.setWindowTitle("Entry in system");
        dialog.resize(300, 150);

        QLabel      *label = new QLabel("Write password");
        QLineEdit   *passwordEdit = new QLineEdit;
        passwordEdit->setEchoMode(QLineEdit::Password);

        QPushButton *okButton = new QPushButton("OK");
        QPushButton *cancelButton = new QPushButton("Cancel");
        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(okButton);
        buttonLayout->addWidget(cancelButton);


        QVBoxLayout *dialogLayout = new QVBoxLayout(&dialog);
        dialogLayout->addWidget(label);
        dialogLayout->addWidget(passwordEdit);
        dialogLayout->addStretch();
        dialogLayout->addLayout(buttonLayout);

        QObject::connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
        QObject::connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

        int result = dialog.exec();

        if (result == QDialog::Accepted)
        {
            if (passwordEdit->text() == "1234")
                QMessageBox::information(&window, "GREAT", "open");
            else
                QMessageBox::information(&window, "ERROR", "accept denied");
        }
    });

    window.show();
    app.exec();
}
