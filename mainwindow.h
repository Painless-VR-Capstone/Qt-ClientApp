#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QColor>
#include <QJsonObject>
#include <QTabWidget>
#include "tasktab.h"
#include "audiotab.h"
#include "visualtab.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

enum Tab {
    Task,
    Audio,
    Visual
};

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionSave_triggered();

    void on_actionSave_Preset_As_Stand_Alone_triggered();

    void on_actionOpen_Preset_triggered();

    void on_actionRun_on_Monitor_triggered();

    void on_actionRun_on_HMD_triggered();

    void on_actionNew_Preset_triggered();

private:
    Ui::MainWindow *mainWindowUi;
    void writeToFile(QFile *file, bool withMessage);
    void setPreviewColor();
    QJsonObject getJSONObject();
    TaskTab *taskTab;
    AudioTab *audioTab;
    VisualTab *visualTab;
    Tab currentTab;

};

#endif // MAINWINDOW_H
