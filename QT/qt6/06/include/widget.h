#ifndef WIDGET_H
# define WIDGET_H

# include <QWidget>
# include <QEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    bool    event(QEvent *e) override;
};


#endif // WIDGET_H
