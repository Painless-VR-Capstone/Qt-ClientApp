#ifndef TASKTAB_H
#define TASKTAB_H

#include <QWidget>
#include "task_passiveflyaround.h"
#include <QJsonObject>
#include "task_objectiveflyaround.h"
#include <QGridLayout>
#include "task_platformhopperleft.h"
#include "task_platformhopperright.h"

namespace Ui {
class TaskTab;
}

class TaskTab : public QWidget
{
    Q_OBJECT

enum TaskLayout {
    passiveFlyAround = 1,
    platformHopper = 2,
    objectiveFlyAround = 3
};

public:
    explicit TaskTab(QWidget *parent = 0);
    ~TaskTab();
    void addValuesToJson(QJsonObject *json);
    void setValuesFromJson(QJsonObject json);

private slots:
    void on_passiveButton_clicked();

    void on_objectiveFlyAroundButton_clicked();

    void on_platformHopperButton_clicked();

private:
    Ui::TaskTab *taskTabUi;
    Task_PassiveFlyAround *passiveFlyAroundWidget;
    QWidget *emptyWidget;
    Task_PassiveFlyAround *leftObjectiveFlyAroundWidget;
    Task_ObjectiveFlyAround *rightObjectiveFlyAroundWidget;
    Task_PlatformHopperLeft *leftPlatformHopperWidget;
    Task_PlatformHopperRight *rightPlatformHopperWidget;
    TaskLayout currentTask;
    QString taskButtonStyle;
    QString whiteBackground;
    QString emptyStyle;
    QString greenBackgound;
    QString frameStyle;

    void readInStyleSheets();
    void setTaskOptionsLayout(TaskLayout newLayout, bool forceLayout = false);
    void removeAllChildrenOfLayout(QGridLayout *layout);
};

#endif // TASKTAB_H
