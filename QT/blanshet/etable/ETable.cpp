#include "ETable.hpp"
#include <QStatusBar>
#include <QLabel>
#include <QCloseEvent>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>

ETable::ETable()
{
    statusBar()->showMessage("Готово");
    QLabel *central = new QLabel("Это главное окно", this);
    setCentralWidget(central);


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
void ETable::open() {}
bool ETable::save() { return true; }
bool ETable::saveAs() { return true; }
void ETable::find() {}
void ETable::goToCell() {}
void ETable::sort() {}
void ETable::about() {}
void ETable::openRecentFile() {}
void ETable::updateStatusBar() {}
void ETable::spreadsheetModified() {}

void ETable::createActions() {}
void ETable::createMenus()
{
    fileMenu = menuBar()->addMenu("&Файл");
}
void ETable::createContextMenu() {}
void ETable::createToolBars() {}
void ETable::createStatusBar() {}
void ETable::readSettings() {}
void ETable::writeSettings() {}
bool ETable::okToContinue() { return true; }
bool ETable::loadFile(const QString &) { return true; }
bool ETable::saveFile(const QString &) { return true; }
void ETable::setCurrentFile(const QString &) {}
void ETable::updateRecentFileActions() {}
QString ETable::strippedName(const QString &s) { return s; }
