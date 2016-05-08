#include "tasktab.h"
#include "ui_tasktab.h"
#include <QGridLayout>
#include <QDebug>
#include <QPalette>
#include <QColor>
#include "utils.h"
#include <QResource>
#include <QTextStream>
#include <QFile>

TaskTab::TaskTab(QWidget *parent) :
    QWidget(parent),
    taskTabUi(new Ui::TaskTab)
{
    taskTabUi->setupUi(this);
    passiveFlyAroundWidget = new Task_PassiveFlyAround(taskTabUi->taskOptionsWidget);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(passiveFlyAroundWidget);
    taskTabUi->taskOptionsWidget->setLayout(layout);
    readInStyleSheets();

    // Set button style sheets
    taskTabUi->passiveButton->setStyleSheet(taskButtonStyle);
    taskTabUi->coinCollectorButton->setStyleSheet(taskButtonStyle);
    taskTabUi->puzzleSolverButton->setStyleSheet(taskButtonStyle);
    taskTabUi->platformHopperButton->setStyleSheet(taskButtonStyle);
    // Set taskBox style sheets
    taskTabUi->taskBox->setStyleSheet(taskBoxStyle);
    Utils::giveWidgetShadow(taskTabUi->taskBox, false);

    // Set Buttons to have no focus so system doesn't auto highlight them
    taskTabUi->passiveButton->setFocusPolicy(Qt::NoFocus);
    taskTabUi->coinCollectorButton->setFocusPolicy(Qt::NoFocus);
    taskTabUi->puzzleSolverButton->setFocusPolicy(Qt::NoFocus);
    taskTabUi->platformHopperButton->setFocusPolicy(Qt::NoFocus);

    // Set Buttons auto-exclusive so only one of them can be checked at a time
    taskTabUi->passiveButton->setAutoExclusive(true);
    taskTabUi->coinCollectorButton->setAutoExclusive(true);
    taskTabUi->platformHopperButton->setAutoExclusive(true);
    taskTabUi->puzzleSolverButton->setAutoExclusive(true);
    on_passiveButton_clicked();
}

void TaskTab::readInStyleSheets()
{
    taskButtonStyle = Utils::readInStyleSheet("task_button.style");
    taskBoxStyle = Utils::readInStyleSheet("task_options_background_white.style");
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
}

void TaskTab::on_platformHopperButton_clicked()
{
    setTaskOptionsLayout(platformHopper);
    taskTabUi->platformHopperButton->setChecked(true);
}

void TaskTab::on_coinCollectorButton_clicked()
{
    setTaskOptionsLayout(coinCollector);
    taskTabUi->coinCollectorButton->setChecked(true);
}

void TaskTab::on_puzzleSolverButton_clicked()
{
    setTaskOptionsLayout(puzzleSolver);
    taskTabUi->puzzleSolverButton->setChecked(true);
}
