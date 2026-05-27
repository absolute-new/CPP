#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>
#include <QChar>
#include "ui_sortdialog.h"
namespace Ui {

class sortDialog : public QDialog, public Ui::SortDialog
{
    Q_OBJECT

public:
    explicit sortDialog(QWidget *parent = nullptr);
    void setColumnRange(QChar first, QChar last);
    ~sortDialog();

private:
    Ui::SortDialog *ui;
};

};

#endif // DIALOG_H
