#include "../include/mylineedit.h"
#include <QDebug>

MyLineEdit::MyLineEdit(int id, QWidget *parent) : QLineEdit(parent), id_(id) {}

void    MyLineEdit::focusInEvent(QFocusEvent *e)
{
    qDebug() << "Получен фокус полем" << id_;
    QLineEdit::focusInEvent(e);
}

void    MyLineEdit::focusOutEvent(QFocusEvent *e)
{
    qDebug() << "Потерян фокус полем" << id_;
    QLineEdit::focusOutEvent(e);
}
