#include "ETable.hpp"
#include <QStatusBar>
#include <QLabel>
#include <QCloseEvent>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>
#include <QFileDialog>

ETable::ETable()
{
    statusBar()->showMessage("Готово");
    spreadsheet = new Spreadsheet(this);
    setCentralWidget(spreadsheet);
    setWindowTitle("Электронная таблица");
    resize(900, 700);
    createMenus();
}

void ETable::closeEvent(QCloseEvent *event)
{
    // Пока просто принимаем закрытие
    event->accept();
}

// Пока все слоты пустые (обязаны существовать, но ничего не делают)
void ETable::newFile() {}
void ETable::open()
{
    QString filename = QFileDialog::getOpenFileName(this, "Открыть файл", ".", "Таблицы (*.csv)");
    if (!filename.isEmpty())
    {
        if (spreadsheet->readFile(filename))
            statusBar()->showMessage("Файл загружен", 2000);
    }
    else
        QMessageBox::warning(this, "Ошибка",
                             "Не удалось открыть файл");
}
bool ETable::save()
{
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}
bool ETable::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Сохранить как", ".", "Таблицы (*.csv)");
    if (fileName.isEmpty()) {
        return false;
    }
    return saveFile(fileName);
}

void ETable::find() {}
void ETable::goToCell() {}
void ETable::sort() {}
void ETable::about()
{
    QMessageBox::about(this, "О программе",
                       "Электронная таблица v1.0\n");
}
void ETable::openRecentFile() {}
void ETable::updateStatusBar() {}
void ETable::spreadsheetModified() {}

void ETable::createActions() {}
void ETable::createMenus()
{
    fileMenu = menuBar()->addMenu("&Файл");
    fileMenu->addAction("&Новый", this, &ETable::newFile, QKeySequence::New);
    fileMenu->addAction("&Открыть", this, &ETable::open, QKeySequence::Open);
    fileMenu->addAction("&Сохранить", this, &ETable::save, QKeySequence::Save);
    fileMenu->addAction("Сохранить &как...", this, &ETable::saveAs, QKeySequence::SaveAs);

    QMenu *helpMenu = menuBar()->addMenu("&Помощь");
    helpMenu->addAction("&О Программе", this, &ETable::about);
}
void ETable::createContextMenu() {}
void ETable::createToolBars() {}
void ETable::createStatusBar() {}
void ETable::readSettings() {}
void ETable::writeSettings() {}
bool ETable::okToContinue() { return true; }
bool ETable::loadFile(const QString &) { return true; }
bool ETable::saveFile(const QString &fileName)
{
    if (spreadsheet->writeFile(fileName)) {
        setCurrentFile(fileName);
        statusBar()->showMessage("Файл сохранён", 2000);
        return true;
    } else {
        QMessageBox::warning(this, "Ошибка",
                             "Не удалось сохранить файл");
        return false;
    }
}
void ETable::setCurrentFile(const QString &) {}
void ETable::updateRecentFileActions() {}
QString ETable::strippedName(const QString &s) { return s; }
