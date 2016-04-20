#ifndef TASKTAB_H
#define TASKTAB_H

#include <QWidget>
#include "task_passiveflyaround.h"
#include "task_platformhopper.h"

namespace Ui {
    class TaskTab;
}

class TaskTab : public QWidget
{
    Q_OBJECT

enum TaskLayout {
    passiveFlyAround,
    platformHopper,
    coinCollector,
    puzzleSolver
};

public:
    explicit TaskTab(QWidget *parent = 0);
    ~TaskTab();

private slots:
    void on_passiveButton_clicked();

    void on_platformHopperButton_clicked();

    void on_coinCollectorButton_clicked();

    void on_puzzleSolverButton_clicked();

private:
    Ui::TaskTab *taskTabUi;
    Task_PassiveFlyAround *passiveFlyAroundWidget;
    Task_PlatformHopper *platformHopperWidget;
    TaskLayout layout;

    void setTaskOptionsLayout(TaskLayout newLayout);
};

#endif // TASKTAB_H
