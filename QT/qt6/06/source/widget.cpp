#include "../include/widget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) : QWidget(parent) {}

Widget::~Widget() {}

bool    Widget::event(QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        qDebug() << "Нажата клавиша на клавиатуре";
        QKeyEvent *k = static_cast<QKeyEvent*>(e);
        qDebug() << "Код:" << k->key() << "текст:" << k->text();
    }
    else if (e->type() == QEvent::Close)
    {
        qDebug() << "Окно закрыто";
    }
    else if (e->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "Щелчок мышью";
        QMouseEvent *m = static_cast<QMouseEvent*>(e);
        qDebug() << "Координаты:" << m->position();
    }

    return QWidget::event(e);
}
