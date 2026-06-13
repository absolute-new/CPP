#ifndef SPREADSHEET_HPP
# define SPREADSHEET_HPP

# include <QTableWidget>

class Spreadsheet : public QTableWidget
{
public:
    Spreadsheet(QWidget *parent = nullptr);

    void clear();
    void copy();
    bool writeFile(const QString &filename);
    bool readFile(const QString &filename);
};

#endif
