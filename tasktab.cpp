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

TaskTab::TaskTab(QWidget *parent) :
    QWidget(parent),
    taskTabUi(new Ui::TaskTab)
{
    taskTabUi->setupUi(this);
    passiveFlyAroundWidget = new Task_PassiveFlyAround(taskTabUi->column0Box);
    objectiveFlyAroundWidget = new Task_ObjectiveFlyAround(taskTabUi->column1Box);
    platformHopperWidget = new Task_PlatformHopper(taskTabUi->column0Box);
    emptyWidget = new QWidget(taskTabUi->column1Box);
    QGridLayout *column0Layout = new QGridLayout();
    QGridLayout *column1Layout = new QGridLayout();
    taskTabUi->column0Box->setLayout(column0Layout);
    taskTabUi->column1Box->setLayout(column1Layout);

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
    QPalette palette = passiveFlyAroundWidget->palette();
    palette.setColor(QPalette::Background, Qt::red);
    passiveFlyAroundWidget->setAutoFillBackground(true);
    passiveFlyAroundWidget->setPalette(palette);
//    palette = platformHopperWidget->palette();
//    palette.setColor(QPalette::Background, Qt::blue);
//    platformHopperWidget->setAutoFillBackground(true);
//    platformHopperWidget->setPalette(palette);
    palette = objectiveFlyAroundWidget->palette();
    palette.setColor(QPalette::Background, Qt::yellow);
    objectiveFlyAroundWidget->setAutoFillBackground(true);
    objectiveFlyAroundWidget->setPalette(palette);
    palette = emptyWidget->palette();
    palette.setColor(QPalette::Background, Qt::green);
    emptyWidget->setAutoFillBackground(true);
    emptyWidget->setPalette(palette);
    /*
     * END TEST CODE
     */
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

void TaskTab::addWidgetToLayout(QGridLayout *layout, int column, QWidget *widget)
{
    layout->addWidget(widget, 0, column);
    layout->setColumnStretch(column, 1);
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

void TaskTab::setTaskOptionsLayout(TaskLayout newLayout)
{
    if (currentTask == newLayout)
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
        taskTabUi->column0Box->update();
        taskTabUi->column1Box->update();
        break;
    case platformHopper:
        break;
    case objectiveFlyAround:
        removeAllChildrenOfLayout(column0Layout);
        removeAllChildrenOfLayout(column1Layout);
        column0Layout->addWidget(passiveFlyAroundWidget, 0, 0);
        column0Layout->addWidget(spacer0, 1, 0);
        column1Layout->addWidget(objectiveFlyAroundWidget, 0, 0);
        column1Layout->addWidget(spacer1, 1, 0);
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
