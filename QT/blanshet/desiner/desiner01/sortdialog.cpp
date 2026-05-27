#include "sortdialog.h"
#include "ui_sortdialog.h"

Ui::sortDialog::sortDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);

    secondaryGroupBox->hide();
    tertriaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    setColumnRange('A', 'Z');
}

void Ui::sortDialog::setColumnRange(QChar first, QChar last)
{
    primaryColumnCombo->clear();
    secondaryColumnCombo->clear();
    tertiaryColumnCombo->clear();

    secondaryColumnCombo->addItem(tr("None"));
    tertiaryColumnCombo->addItem(tr("None"));
    primaryColumnCombo->setMinimumSize(secondaryColumnCombo->sizeHint());
    QChar ch = first;
    while (ch <= last)
    {
        primaryColumnCombo->addItem(QString(ch));
        secondaryColumnCombo->addItem(QString(ch));
        tertiaryColumnCombo->addItem(QString(ch));
        ch = QChar(ch.unicode() + 1);
    }
}

Ui::sortDialog::~sortDialog() {}
