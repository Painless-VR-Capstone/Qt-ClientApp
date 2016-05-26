#include "tasktab.h"
#include "ui_tasktab.h"
#include <QDebug>
#include <QPalette>
#include <QColor>
#include "utils.h"
#include <QResource>
#include <QTextStream>
#include <QFile>
#include <QSpacerItem>

static const QString KEY_TASK = "task";

TaskTab::TaskTab(QWidget *parent) :
    QWidget(parent),
    taskTabUi(new Ui::TaskTab)
{
    taskTabUi->setupUi(this);
    passiveFlyAroundWidget = new Task_PassiveFlyAround();
    leftObjectiveFlyAroundWidget = new Task_PassiveFlyAround();
    rightObjectiveFlyAroundWidget = new Task_ObjectiveFlyAround();
    leftPlatformHopperWidget = new Task_PlatformHopperLeft();
    rightPlatformHopperWidget = new Task_PlatformHopperRight();
    emptyWidget = new QWidget(taskTabUi->column1Box);
    QGridLayout *column0Layout = new QGridLayout();
    QGridLayout *column1Layout = new QGridLayout();
    column0Layout->setContentsMargins(0, 0, 0, 0);
    column1Layout->setContentsMargins(0, 0, 0, 0);
    taskTabUi->column0Box->setLayout(column0Layout);
    taskTabUi->column1Box->setLayout(column1Layout);

    readInStyleSheets();

    // Set button style sheets
    taskTabUi->passiveButton->setStyleSheet(taskButtonStyle);
    taskTabUi->objectiveFlyAroundButton->setStyleSheet(taskButtonStyle);
    taskTabUi->platformHopperButton->setStyleSheet(taskButtonStyle);
    // Set taskBox style sheets
    taskTabUi->taskBox->setStyleSheet(greenBackgound);
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

    taskTabUi->taskButtonBox->setStyleSheet(whiteBackground);
    taskTabUi->previewBox->setStyleSheet(whiteBackground);
    on_passiveButton_clicked();
}

void TaskTab::readInStyleSheets()
{
    taskButtonStyle = Utils::readInStyleSheet("task_button.style");
    whiteBackground = Utils::readInStyleSheet("task_options_background_white.style");
    emptyStyle = Utils::readInStyleSheet("transparent_background.style");
    greenBackgound = Utils::readInStyleSheet("task_options_background_green.style");
    frameStyle = Utils::readInStyleSheet("frame_style.style");
}

TaskTab::~TaskTab()
{
    delete taskTabUi;
}

void TaskTab::removeAllChildrenOfLayout(QGridLayout *layout)
{
    QLayoutItem *child = layout->takeAt(0);
    int i = 0;
    while(child != 0)
    {
        child = layout->takeAt(0);
        i++;
    }
    qDebug() << "removed" << i << "widgets from the optionsBox";
}

void TaskTab::setTaskOptionsLayout(TaskLayout newLayout, bool forceLayout)
{
    if (currentTask == newLayout && !forceLayout)
    {
        return;
    }

    QGridLayout *column0Layout = ((QGridLayout *) taskTabUi->column0Box->layout());
    QGridLayout *column1Layout = ((QGridLayout *) taskTabUi->column1Box->layout());
    QWidget *spacer0 = new QWidget();
    QWidget *spacer1 = new QWidget();
    spacer0->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    spacer1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);

    switch (newLayout)
    {
    case passiveFlyAround:
        removeAllChildrenOfLayout(column0Layout);
        removeAllChildrenOfLayout(column1Layout);
        column0Layout->addWidget(passiveFlyAroundWidget, 0, 0);
        column0Layout->addWidget(spacer0, 1, 0);
        column1Layout->addWidget(emptyWidget, 0, 0);
        column1Layout->addWidget(spacer1, 1, 0);
        passiveFlyAroundWidget->setVisible(true);
        leftObjectiveFlyAroundWidget->setVisible(false);
        rightObjectiveFlyAroundWidget->setVisible(false);
        leftPlatformHopperWidget->setVisible(false);
        rightPlatformHopperWidget->setVisible(false);
        emptyWidget->setVisible(true);
        taskTabUi->column0Box->update();
        taskTabUi->column1Box->update();
        break;
    case platformHopper:
        removeAllChildrenOfLayout(column0Layout);
        removeAllChildrenOfLayout(column1Layout);
        column0Layout->addWidget(leftPlatformHopperWidget, 0, 0);
        column0Layout->addWidget(spacer0, 1, 0);
        column1Layout->addWidget(rightPlatformHopperWidget, 0, 0);
        column1Layout->addWidget(spacer1, 1, 0);
        passiveFlyAroundWidget->setVisible(false);
        leftObjectiveFlyAroundWidget->setVisible(false);
        rightObjectiveFlyAroundWidget->setVisible(false);
        leftPlatformHopperWidget->setVisible(true);
        rightPlatformHopperWidget->setVisible(true);
        emptyWidget->setVisible(false);
        taskTabUi->column0Box->update();
        taskTabUi->column1Box->update();
        break;
    case objectiveFlyAround:
        removeAllChildrenOfLayout(column0Layout);
        removeAllChildrenOfLayout(column1Layout);
        column0Layout->addWidget(leftObjectiveFlyAroundWidget, 0, 0);
        column0Layout->addWidget(spacer0, 1, 0);
        column1Layout->addWidget(rightObjectiveFlyAroundWidget, 0, 0);
        column1Layout->addWidget(spacer1, 1, 0);
        passiveFlyAroundWidget->setVisible(false);
        leftObjectiveFlyAroundWidget->setVisible(true);
        rightObjectiveFlyAroundWidget->setVisible(true);
        leftPlatformHopperWidget->setVisible(false);
        rightPlatformHopperWidget->setVisible(false);
        emptyWidget->setVisible(false);
        taskTabUi->column0Box->update();
        taskTabUi->column1Box->update();
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

void TaskTab::setValuesFromJson(QJsonObject json)
{
    TaskLayout task = passiveFlyAround;
    if (json.contains(KEY_TASK))
    {
        int i = json.value(KEY_TASK).toInt(1);
        switch (i) {
        case 1:
            task = passiveFlyAround;
            break;
        case 2:
            task = platformHopper;
            break;
        case 3:
            task = objectiveFlyAround;
            break;
        }
    }
    currentTask = task;
    switch (currentTask)
    {
    case passiveFlyAround:
        passiveFlyAroundWidget->setValuesFromJson(json);
        setTaskOptionsLayout(passiveFlyAround, true);
        taskTabUi->passiveButton->setChecked(true);
        break;
    case objectiveFlyAround:
        leftObjectiveFlyAroundWidget->setValuesFromJson(json);
        rightObjectiveFlyAroundWidget->setValuesFromJson(json);
        setTaskOptionsLayout(objectiveFlyAround, true);
        taskTabUi->objectiveFlyAroundButton->setChecked(true);
        break;
    case platformHopper:
        leftPlatformHopperWidget->setValuesFromJson(json);
        rightPlatformHopperWidget->setValuesFromJson(json);
        setTaskOptionsLayout(platformHopper, true);
        taskTabUi->platformHopperButton->setChecked(true);
        break;
    }
}





















