#ifndef ETABLE_HPP
# define ETABLE_HPP

# include <QMainWindow>

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

class ETable : public QMainWindow
{
    Q_OBJECT

public:
    ETable();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToCell();
    void sort();
    void about();
    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();

private:
    void createActions();                       // создать действия (меню, тулбары)
    void createMenus();                         // создать меню
    void createContextMenu();                   // контекстное меню (по правой кнопке)
    void createToolBars();                      // панели инструментов
    void createStatusBar();                     // строка состояния (внизу)
    void readSettings();                        // прочитать сохранённые настройки
    void writeSettings();                       // сохранить настройки
    bool okToContinue();                        // спросить "Сохранить?" при закрытии
    bool loadFile(const QString &fileName);     // загрузить файл
    bool saveFile(const QString &fileName);     // сохранить файл
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();             // обновить список "Последние файлы"
    QString strippedName(const QString &fullFileName);

    Spreadsheet *spreadsheet;                   // центральный виджет с таблицей
    FindDialog *findDialog;                     // диалог поиска (создаётся при первом вызове)
    QLabel *locationLabel;                      // метка в статусной строке
    QLabel *formulaLabel;                       // метка для формулы

    QStringList recentFiles;                    // список последних файлов
    QString curFile;                            // текущий открытый файл

    enum { MaxRecentFiles = 5 };
    QAction *recentFileActions[MaxRecentFiles]; // действия для пунктов "Недавние файлы"
    QAction *separatorAction;                   // разделитель в меню

    QMenu *fileMenu;                            // меню Файл
    QMenu *editMenu;                            // меню Правка
    QToolBar *fileToolBar;                      // панель инструментов Файл
    QToolBar *editToolBar;                      // панель инструментов Правка

    QAction *newAction;                         // действие "Создать"
    QAction *openAction;                        // действие "Открыть"
    QAction *aboutQtAction;
};


#endif
