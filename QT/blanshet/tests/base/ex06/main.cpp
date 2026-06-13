#include <QApplication>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QWidget>
#include <QFont>

int main(int argc, char* argv[])
{
    QApplication    app(argc, argv);

    QWidget         window;
    window.resize(300, 200);
    window.setWindowTitle("MAIN");

    QLabel          *label = new QLabel("TEXT");
    label->setAlignment(Qt::AlignCenter);

    QCheckBox       *checkBox = new QCheckBox("BOLD");

    QRadioButton    *smallFont = new QRadioButton("small font(12 pt)");
    QRadioButton    *largeFont = new QRadioButton("big font(16 pt)");
    smallFont->setChecked(true);

    QVBoxLayout     *layout = new QVBoxLayout(&window);
    layout->addWidget(label);
    layout->addWidget(checkBox);
    layout->addWidget(smallFont);
    layout->addWidget(largeFont);

    auto updateStyle = [&](){
        QFont font = label->font();
        font.setBold(checkBox->isChecked());

        if (smallFont->isChecked())
            font.setPointSize(12);
        else
            font.setPointSize(16);
        label->setFont(font);
    };

    QObject::connect(checkBox, &QCheckBox::toggled, updateStyle);
    QObject::connect(smallFont, &QRadioButton::toggled, updateStyle);
    QObject::connect(largeFont, &QRadioButton::toggled, updateStyle);

    window.show();
    return app.exec();
}
