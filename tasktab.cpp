#include "tasktab.h"
#include "ui_tasktab.h"
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
    passiveFlyAroundWidget = new Task_PassiveFlyAround(taskTabUi->passiveFlyAroundBox);
    objectiveFlyAroundWidget = new Task_ObjectiveFlyAround(taskTabUi->objectiveFlyAroundBox);
    platformHopperWidget = new Task_PlatformHopper(taskTabUi->platformHopperButton);
    QGridLayout *passiveLayout = new QGridLayout();
    QGridLayout *objectiveLayout = new QGridLayout();
    QGridLayout *platformLayout = new QGridLayout();
    passiveLayout->addWidget(passiveFlyAroundWidget);
    objectiveLayout->addWidget(objectiveFlyAroundWidget);
    platformLayout->addWidget(platformHopperWidget);
    QPalette palette = taskTabUi->emptyBox->palette();
    palette.setColor(QPalette::Background, QColor(Qt::transparent));
    taskTabUi->emptyBox->setAutoFillBackground(true);
    taskTabUi->emptyBox->setPalette(palette);
    taskTabUi->emptyBox->update();
    taskTabUi->passiveFlyAroundBox->setFixedHeight(passiveLayout->sizeHint().height());
    taskTabUi->platformHopperBox->setFixedHeight(platformLayout->sizeHint().height());
    taskTabUi->objectiveFlyAroundBox->setFixedHeight(objectiveLayout->sizeHint().height());

    readInStyleSheets();

    // Set button style sheets
    taskTabUi->passiveButton->setStyleSheet(taskButtonStyle);
    taskTabUi->objectiveFlyAroundButton->setStyleSheet(taskButtonStyle);
    taskTabUi->platformHopperButton->setStyleSheet(taskButtonStyle);
    // Set taskBox style sheets
    taskTabUi->taskBox->setStyleSheet(taskBoxStyle);
    Utils::giveWidgetShadow(taskTabUi->taskBox, false);

    // Set Buttons to have no focus so system doesn't auto highlight them
    taskTabUi->passiveButton->setFocusPolicy(Qt::NoFocus);
    taskTabUi->objectiveFlyAroundButton->setFocusPolicy(Qt::NoFocus);
    taskTabUi->platformHopperButton->setFocusPolicy(Qt::NoFocus);

    // Set Buttons auto-exclusive so only one of them can be checked at a time
    taskTabUi->passiveButton->setAutoExclusive(true);
    taskTabUi->platformHopperButton->setAutoExclusive(true);
    taskTabUi->objectiveFlyAroundButton->setAutoExclusive(true);
    on_passiveButton_clicked();

    /*
     * TEST CODE
     */
    palette = taskTabUi->passiveWidget->palette();
    palette.setColor(QPalette::Background, QColor(Qt::red));
    taskTabUi->passiveWidget->setAutoFillBackground(true);
    taskTabUi->passiveWidget->setPalette(palette);
    palette = taskTabUi->platformWidget->palette();
    palette.setColor(QPalette::Background, QColor(Qt::blue));
    taskTabUi->platformWidget->setAutoFillBackground(true);
    taskTabUi->platformWidget->setPalette(palette);
    palette = taskTabUi->emptyWidget->palette();
    palette.setColor(QPalette::Background, QColor(Qt::green));
    taskTabUi->emptyWidget->setAutoFillBackground(true);
    taskTabUi->emptyWidget->setPalette(palette);
    palette = taskTabUi->objectiveWidget->palette();
    palette.setColor(QPalette::Background, QColor(Qt::yellow));
    taskTabUi->objectiveWidget->setAutoFillBackground(true);
    taskTabUi->objectiveWidget->setPalette(palette);
}

void TaskTab::readInStyleSheets()
{
    taskButtonStyle = Utils::readInStyleSheet("task_button.style");
    taskBoxStyle = Utils::readInStyleSheet("task_options_background_white.style");
    emptyStyle = Utils::readInStyleSheet("transparent_background.style");
}

TaskTab::~TaskTab()
{
    delete taskTabUi;
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
//        taskTabUi->passiveFlyAroundBox->setVisible(true);
//        taskTabUi->emptyBox->setVisible(true);
//        taskTabUi->platformHopperBox->setVisible(false);
//        taskTabUi->objectiveFlyAroundBox->setVisible(false);
        taskTabUi->passiveWidget->setVisible(true);
        taskTabUi->emptyBox->setVisible(true);
        taskTabUi->platformHopperBox->setVisible(false);
        taskTabUi->objectiveFlyAroundBox->setVisible(false);
        taskTabUi->passiveFlyAroundBox->setStyleSheet(taskBoxStyle);
        taskTabUi->platformHopperBox->setStyleSheet(emptyStyle);
        taskTabUi->objectiveFlyAroundBox->setStyleSheet(emptyStyle);
        Utils::giveWidgetShadow(taskTabUi->passiveFlyAroundBox);
        taskTabUi->platformHopperBox->setGraphicsEffect(NULL);
        taskTabUi->objectiveFlyAroundBox->setGraphicsEffect(NULL);
        break;
    case platformHopper:
//        taskTabUi->passiveFlyAroundBox->setVisible(false);
//        taskTabUi->emptyBox->setVisible(true);
//        taskTabUi->platformHopperBox->setVisible(true);
//        taskTabUi->objectiveFlyAroundBox->setVisible(false);
        taskTabUi->passiveWidget->setVisible(false);
        taskTabUi->emptyBox->setVisible(true);
        taskTabUi->platformHopperBox->setVisible(true);
        taskTabUi->objectiveFlyAroundBox->setVisible(false);
        taskTabUi->passiveFlyAroundBox->setStyleSheet(emptyStyle);
        taskTabUi->platformHopperBox->setStyleSheet(taskBoxStyle);
        taskTabUi->objectiveFlyAroundBox->setStyleSheet(emptyStyle);
        taskTabUi->passiveFlyAroundBox->setGraphicsEffect(NULL);
        Utils::giveWidgetShadow(taskTabUi->platformHopperBox);
        taskTabUi->passiveFlyAroundBox->setGraphicsEffect(NULL);
        break;
    case objectiveFlyAround:
//        taskTabUi->passiveFlyAroundBox->setVisible(true);
//        taskTabUi->emptyBox->setVisible(false);
//        taskTabUi->platformHopperBox->setVisible(false);
//        taskTabUi->objectiveFlyAroundBox->setVisible(true);
        taskTabUi->passiveWidget->setVisible(true);
        taskTabUi->emptyBox->setVisible(false);
        taskTabUi->platformHopperBox->setVisible(false);
        taskTabUi->objectiveFlyAroundBox->setVisible(true);
        taskTabUi->passiveFlyAroundBox->setStyleSheet(taskBoxStyle);
        taskTabUi->platformHopperBox->setStyleSheet(emptyStyle);
        taskTabUi->objectiveFlyAroundBox->setStyleSheet(taskBoxStyle);
        Utils::giveWidgetShadow(taskTabUi->passiveFlyAroundBox);
        taskTabUi->platformHopperBox->setGraphicsEffect(NULL);
        Utils::giveWidgetShadow(taskTabUi->objectiveFlyAroundBox);
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
    case objectiveFlyAround:
        task = 3;
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

void TaskTab::on_objectiveFlyAroundButton_clicked()
{
    setTaskOptionsLayout(objectiveFlyAround);
    taskTabUi->objectiveFlyAroundButton->setChecked(true);
}

void TaskTab::on_platformHopperButton_clicked()
{
    setTaskOptionsLayout(platformHopper);
    taskTabUi->platformHopperButton->setChecked(true);
}
