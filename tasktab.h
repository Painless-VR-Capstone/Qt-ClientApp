#ifndef TASKTAB_H
#define TASKTAB_H

#include <QWidget>
#include "task_passiveflyaround.h"
#include "task_platformhopper.h"
#include <QJsonObject>
#include "task_objectiveflyaround.h"
#include <QGridLayout>

namespace Ui {
    class TaskTab;
}

class TaskTab : public QWidget
{
    Q_OBJECT

enum TaskLayout {
    passiveFlyAround,
    platformHopper,
    objectiveFlyAround
};

public:
    explicit TaskTab(QWidget *parent = 0);
    ~TaskTab();
    void addValuesToJson(QJsonObject *json);

private slots:
    void on_passiveButton_clicked();

    void on_objectiveFlyAroundButton_clicked();

    void on_platformHopperButton_clicked();

private:
    Ui::TaskTab *taskTabUi;
    Task_PassiveFlyAround *passiveFlyAroundWidget;
    Task_PlatformHopper *platformHopperWidget;
    Task_ObjectiveFlyAround *objectiveFlyAroundWidget;
    TaskLayout currentTask;
    QString taskButtonStyle;
    QString taskBoxStyle;

    void readInStyleSheets();
    void setTaskOptionsLayout(TaskLayout newLayout);
};

#endif // TASKTAB_H
