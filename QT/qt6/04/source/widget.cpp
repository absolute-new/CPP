#include "../include/widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent)
{
    timerID = -1;
    label = new QLabel("");
    label->setAlignment(Qt::AlignCenter);
    btn1 = new QPushButton("Запустить");
    btn2 = new QPushButton("Остановить");
    btn2->setEnabled(false);
    vbox = new QVBoxLayout(this);
    vbox->addWidget(label);
    vbox->addWidget(btn1);
    vbox->addWidget(btn2);
    setLayout(vbox);
    connect(btn1, &QPushButton::clicked, this, &Widget::on_btn1_clicked);
    connect(btn2, &QPushButton::clicked, this, &Widget::on_btn2_clicked);
}

void    Widget::on_btn1_clicked()
{
    timerID = startTimer(1000);  // 1 sec
    btn1->setEnabled(false);
    btn2->setEnabled(true);
}

void    Widget::on_btn2_clicked()
{
    if (timerID != -1)
    {
        killTimer(timerID);
        timerID = -1;
    }
    btn1->setEnabled(true);
    btn2->setEnabled(false);
}

void    Widget::timerEvent(QTimerEvent* event)
{
    QTime t = QTime::currentTime();
    label->setText(t.toString("HH:mm:ss"));
}

Widget::~Widget()
{
    qDebug() << "=== ДЕТИ WIDGET ===";
    qDebug() << "Всего детей:" << children().size();
    
    // Список детей
    for (auto child : children()) {
        qDebug() << "  -" << child->metaObject()->className();
    }
}
