#include "../include/widget.h"
#include <QDebug>

Widget::Widget(QWidget* parent) : QWidget(parent)
{
    btn1 = new QPushButton("Нажми меня");
    btn2 = new QPushButton("Кнопка 2");
    vbox = new QVBoxLayout();
    vbox->addWidget(btn1);
    vbox->addWidget(btn2);
    setLayout(vbox);
    connect(btn1, &QPushButton::clicked, this, &Widget::on_btn1_clicked);
    connect(btn2, &QPushButton::clicked, this, &Widget::on_btn2_clicked);
    connect(this, &Widget::mySignal, this, &Widget::on_mySignal);
}

void    Widget::on_btn1_clicked()
{
    qDebug() << "Нажата кнопка 1";
    emit btn2->clicked();
    emit mySignal(10, 20);
}

void    Widget::on_btn2_clicked()
{
    qDebug() << "Нажата кнопка 2";
}

void    Widget::on_mySignal(int a, int b)
{
    qDebug() << "on_mysignal" << a << b;
}

Widget::~Widget() {}
