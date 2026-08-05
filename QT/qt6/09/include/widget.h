#ifndef WIDGET_H
# define WIDGET_H

# include <QWidget>
# include <QMessageBox>
# include <QCloseEvent>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void    closeEvent(QCloseEvent *e) override;
};

#endif // WIDGET_H
