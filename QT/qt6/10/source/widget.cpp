#include "../include/widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    line1 = new MyLineEdit(1);
    line2 = new MyLineEdit(2);
    btn1 = new QPushButton("Установить фокус на поле 2");
    vbox = new QVBoxLayout();
    vbox->addWidget(btn1);
    vbox->addWidget(line1);
    vbox->addWidget(line2);
    setLayout(vbox);
    connect(btn1, &QPushButton::clicked, line2,
            static_cast<void (MyLineEdit::*)()>(&MyLineEdit::setFocus));
    QWidget::setTabOrder(line1, line2);
    QWidget::setTabOrder(line2, btn1);
}

Widget::~Widget() {}
