#include <QApplication>
#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication    app(argc, argv);

    QWidget         window;
    window.setWindowTitle("MAIN WINDOW");
    window.resize(300, 200);

    QPushButton     *openDialogBtn = new QPushButton("Open dialog");
    QVBoxLayout     *layout = new QVBoxLayout(&window);
    layout->addWidget(openDialogBtn);

    QObject::connect(openDialogBtn, &QPushButton::clicked, [&](){
        QDialog     dialog(&window);
        dialog.setWindowTitle("Dialog");
        dialog.resize(250, 150);

        QPushButton *okButton = new QPushButton("OK");
        QPushButton *cancelButton = new QPushButton("Cancel");

        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(okButton);
        buttonLayout->addWidget(cancelButton);

        QVBoxLayout *dialogLayout = new QVBoxLayout(&dialog);
        dialogLayout->addStretch();
        dialogLayout->addLayout(buttonLayout);

        QObject::connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
        QObject::connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

        int res = dialog.exec();

        QMessageBox msgBox;
        if (res == QDialog::Accepted)
        {
            msgBox.setWindowTitle("RESULT");
            msgBox.setText("you push OK");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.exec();
        }
        else if (res == QDialog::Rejected)
        {
            msgBox.setWindowTitle("RESULT");
            msgBox.setText("you push Cancell");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.exec();
        }
    });

    window.show();
    return app.exec();
}
