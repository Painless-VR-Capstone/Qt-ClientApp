#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QColor>
#include <QJsonObject>
#include <QTabWidget>
#include "tasktab.h"
#include "audiotab.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//private slots:
//    void on_saveButton_clicked();
//    void on_saveAsButton_clicked();

private:
    Ui::MainWindow *mainWindowUi;
    void writeToFile(QFile *file);
    void setPreviewColor();
    QJsonObject getJSONObject();
    TaskTab *taskTab;
//    AudioTab audioTab;
};

#endif // MAINWINDOW_H
