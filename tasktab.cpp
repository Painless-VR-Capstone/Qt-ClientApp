#include "tasktab.h"
#include "ui_tasktab.h"
#include <QGridLayout>
#include <QDebug>
#include <QPalette>
#include <QColor>
#include "utils.h"

TaskTab::TaskTab(QWidget *parent) :
    QWidget(parent),
    taskTabUi(new Ui::TaskTab)
{
    taskTabUi->setupUi(this);
    passiveFlyAroundWidget = new Task_PassiveFlyAround(taskTabUi->taskOptionsWidget);
    platformHopperWidget = new Task_PlatformHopper(taskTabUi->taskOptionsWidget);
    /*
     * TEST CODE
     */
//    QPalette palette = taskTabUi->taskOptionsWidget->palette();
//    palette.setColor(QPalette::Background, QColor::fromRgb(0, 0, 255));
//    taskTabUi->taskOptionsWidget->setAutoFillBackground(true);
//    taskTabUi->taskOptionsWidget->setPalette(palette);
//    palette = passiveFlyAroundWidget->palette();
//    palette.setColor(QPalette::Background, QColor::fromRgb(0, 255, 0));
//    passiveFlyAroundWidget->setAutoFillBackground(true);
//    passiveFlyAroundWidget->setPalette(palette);
    /*
     * END TEST CODE
     */
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(passiveFlyAroundWidget);
    taskTabUi->taskOptionsWidget->setLayout(layout);
    on_passiveButton_clicked();
}

TaskTab::~TaskTab()
{
    delete taskTabUi;
//    delete passiveFlyAroundWidget;
//    delete platformHopperWidget;
}

void TaskTab::setTaskOptionsLayout(TaskLayout newLayout)
{
    if (currentTask == newLayout)
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
    currentTask = newLayout;
}


void TaskTab::addValuesToJson(QJsonObject *json)
{
    int task = 1;
    QJsonObject optionsJson;
    switch(currentTask)
    {
    case passiveFlyAround:
        task = 1;
        optionsJson = passiveFlyAroundWidget->getJsonObject();
        break;
    case platformHopper:
        task = 2;
        break;
    case coinCollector:
        task = 3;
        break;
    case puzzleSolver:
        task = 4;
        break;
    }
    json->insert("task", task);
    Utils::mergeJsons(json, optionsJson);
}

void TaskTab::on_passiveButton_clicked()
{
    setTaskOptionsLayout(passiveFlyAround);
    taskTabUi->passiveButton->setChecked(true);
    taskTabUi->platformHopperButton->setChecked(false);
    taskTabUi->coinCollectorButton->setChecked(false);
    taskTabUi->puzzleSolverButton->setChecked(false);
}

void TaskTab::on_platformHopperButton_clicked()
{
    setTaskOptionsLayout(platformHopper);
    taskTabUi->passiveButton->setChecked(false);
    taskTabUi->platformHopperButton->setChecked(true);
    taskTabUi->coinCollectorButton->setChecked(false);
    taskTabUi->puzzleSolverButton->setChecked(false);
}

void TaskTab::on_coinCollectorButton_clicked()
{
    setTaskOptionsLayout(coinCollector);
    taskTabUi->passiveButton->setChecked(false);
    taskTabUi->platformHopperButton->setChecked(false);
    taskTabUi->coinCollectorButton->setChecked(true);
    taskTabUi->puzzleSolverButton->setChecked(false);
}

void TaskTab::on_puzzleSolverButton_clicked()
{
    setTaskOptionsLayout(puzzleSolver);
    taskTabUi->passiveButton->setChecked(false);
    taskTabUi->platformHopperButton->setChecked(false);
    taskTabUi->coinCollectorButton->setChecked(false);
    taskTabUi->puzzleSolverButton->setChecked(true);
}
