#include "Spreadsheet.hpp"
#include <QFile>
#include <QApplication>
#include <QTextStream>

Spreadsheet::Spreadsheet(QWidget *parent) : QTableWidget(parent)
{
    setRowCount(10);
    setColumnCount(10);

    QStringList headers;
    for (char c = 'A'; c <= 'J'; c++)
        headers << QString(c);
    setHorizontalHeaderLabels(headers);
    QStringList rowHeader;
    for (int i = 1; i <= 10; ++i)
        rowHeader << QString::number(i);
    setVerticalHeaderLabels(rowHeader);
}

void Spreadsheet::clear()
{
    setRowCount(0);
    setColumnCount(0);
    setRowCount(10);
    setColumnCount(10);

    QStringList headers;
    for (char c = 'A'; c <= 'J'; ++c)
        headers << QString(c);
    setHorizontalHeaderLabels(headers);

    QStringList rowHeaders;
    for (int i = 1; i <= 10; ++i)
        rowHeaders << QString::number(i);
    setVerticalHeaderLabels(rowHeaders);
}

void Spreadsheet::copy()
{
    QTableWidgetSelectionRange range = selectedRanges();
    QString str;
    for (int i = 0; i < range.rowCount(); ++i)
    {
        if (i > 0)
            str += "\n";
        for (int j = 0; j < range.columnCount(); ++j)
        {
            if (j > 0)
                str += "\t";
            str += fommula(range.topRow() + i, range.leftColumn() + j);
        }
    }
    QApplication::clipboard()->setText(str);
}

bool Spreadsheet::writeFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    QTextStream out(&file);
    for (int row = 0; row < rowCount(); row++)
    {
        QStringList rowData;
        for (int col = 0; col < columnCount(); col++)
        {
            QTableWidgetItem *item = this->item(row, col);
            if (item)
                rowData << item->text();
            else
                rowData << "";
        }
        out << rowData.join(",") << "\n";
    }
    return true;
}

bool Spreadsheet::readFile(const QString& filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly))
        return false;
    clear();
    QTextStream in(&file);
    int row = 0;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList cells = line.split(",");
        for (int col = 0; col < cells.size(); ++col)
            setItem(row, col, new QTableWidgetItem(cells[col]));
        ++row;
    }
    return true;
}
