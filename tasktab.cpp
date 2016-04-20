#include "tasktab.h"
#include "ui_tasktab.h"
#include <QGridLayout>
#include <QDebug>
#include <QPalette>
#include <QColor>

TaskTab::TaskTab(QWidget *parent) :
    QWidget(parent),
    taskTabUi(new Ui::TaskTab)
{
    taskTabUi->setupUi(this);
//    QPalette palette = taskTabUi->taskOptionsWidget->palette();
//    palette.setColor(QPalette::Background, QColor::fromRgb(0, 0, 255));
//    taskTabUi->taskOptionsWidget->setAutoFillBackground(true);
//    taskTabUi->taskOptionsWidget->setPalette(palette);
    passiveFlyAroundWidget = new Task_PassiveFlyAround(taskTabUi->taskOptionsWidget);
    platformHopperWidget = new Task_PlatformHopper(taskTabUi->taskOptionsWidget);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(passiveFlyAroundWidget);
    taskTabUi->taskOptionsWidget->setLayout(layout);
}

TaskTab::~TaskTab()
{
    delete taskTabUi;
//    delete passiveFlyAroundWidget;
//    delete platformHopperWidget;
}

void TaskTab::setTaskOptionsLayout(TaskLayout newLayout)
{
    if (layout == newLayout)
    {
        return;
    }

    switch (newLayout)
    {
    case passiveFlyAround:

        break;
    case platformHopper:

        break;
    case coinCollector:

        break;
    case puzzleSolver:

        break;
    }
}

void TaskTab::on_passiveButton_clicked()
{
    setTaskOptionsLayout(passiveFlyAround);
    taskTabUi->passiveButton->setDown(true);
}

void TaskTab::on_platformHopperButton_clicked()
{
    setTaskOptionsLayout(platformHopper);
    taskTabUi->platformHopperButton->setDown(true);
}

void TaskTab::on_coinCollectorButton_clicked()
{
    setTaskOptionsLayout(coinCollector);
    taskTabUi->coinCollectorButton->setDown(true);
}

void TaskTab::on_puzzleSolverButton_clicked()
{
    setTaskOptionsLayout(puzzleSolver);
    taskTabUi->puzzleSolverButton->setDown(true);
}
