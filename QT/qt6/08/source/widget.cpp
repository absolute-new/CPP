#include "../include/widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent) {}

Widget::~Widget() {}

void    Widget::moveEvent(QMoveEvent *e)
{
    qDebug() << "moveEvent" << e->pos().x() << e->pos().y();
    QWidget::moveEvent(e);
}

void    Widget::resizeEvent(QResizeEvent *e)
{
    qDebug() << "resizeEvent"
             << e->size().width() << e->size().height();
    QWidget::resizeEvent(e);
}
