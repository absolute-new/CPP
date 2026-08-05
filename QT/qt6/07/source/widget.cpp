#include "../include/widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    btn1 = new QPushButton("Полноэкранный режим");
    btn2 = new QPushButton("Нормальный режим");
    vbox = new QVBoxLayout();
    vbox->addWidget(btn1);
    vbox->addWidget(btn2);
    setLayout(vbox);
    connect(btn1, &QPushButton::clicked, this, &Widget::showFullScreen);
    connect(btn2, &QPushButton::clicked, this, &Widget::showNormal);
}

Widget::~Widget() {}

void    Widget::changeEvent(QEvent *e)
{
    if (e->type() == QEvent::WindowStateChange)
    {
        if (isMinimized())
            qDebug() << "Окно свернуто";
        else if (isMaximized())
            qDebug() << "Окно раскрыто до максимальных размеров";
        else if (isFullScreen())
            qDebug() << "Полноэкранный режим";
        else if (isActiveWindow())
            qDebug() << "Окно находится в фокусе ввода";
    }
    QWidget::changeEvent(e);
}

void    Widget::showEvent(QShowEvent *e)
{
    qDebug() << "Окно отображено";
    QWidget::showEvent(e);
}

void    Widget::hideEvent(QHideEvent *e)
{
    qDebug() << "Окно скрыто";
    QWidget::hideEvent(e);
}
