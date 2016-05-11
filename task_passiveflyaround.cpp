#include "task_passiveflyaround.h"
#include "ui_task_passiveflyaround.h"
#include <QIcon>
#include "utils.h"
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QPalette>
#include <QPixmap>
#include <QBrush>
#include <QIcon>
#include <QSize>

Task_PassiveFlyAround::Task_PassiveFlyAround(QWidget *parent) :
    QWidget(parent),
    passiveFlyAroundUi(new Ui::Task_PassiveFlyAround)
{
    passiveFlyAroundUi->setupUi(this);
    readInStyleSheets();
    passiveFlyAroundUi->optionsBox->setStyleSheet(taskBackgroundGreenStyle);
    Utils::giveWidgetShadow(passiveFlyAroundUi->optionsBox);
    passiveFlyAroundUi->movementBox->setStyleSheet(taskBackgroundWhiteStyle);
    passiveFlyAroundUi->elementsBox->setStyleSheet(taskBackgroundWhiteStyle);
    initialButtonSize = passiveFlyAroundUi->switchDirection->size();
    Utils::makeButtonIntoSwitch(passiveFlyAroundUi->switchDirection,
                                initialButtonSize,
                                switchStyle);
    Utils::makeButtonIntoSwitch(passiveFlyAroundUi->switchReactiveEnvironment,
                                initialButtonSize,
                                switchStyle);
    Utils::makeButtonIntoSwitch(passiveFlyAroundUi->switchSpeed,
                                initialButtonSize,
                                switchStyle);
    Utils::makeButtonIntoSwitch(passiveFlyAroundUi->switchTeleporting,
                                initialButtonSize,
                                switchStyle);
    Utils::makeButtonIntoSwitch(passiveFlyAroundUi->switchThrowProjectiles,
                                initialButtonSize,
                                switchStyle);

}

Task_PassiveFlyAround::~Task_PassiveFlyAround()
{
    delete passiveFlyAroundUi;
}

void Task_PassiveFlyAround::readInStyleSheets()
{
    taskBackgroundGreenStyle = Utils::readInStyleSheet("task_options_background_green.style");
    taskBackgroundWhiteStyle = Utils::readInStyleSheet("task_options_background_white.style");
    switchStyle = Utils::readInStyleSheet("switch.style");
}

QJsonObject Task_PassiveFlyAround::getJsonObject()
{
    QJsonObject json;
    return json;
}

void Task_PassiveFlyAround::on_switchSpeed_toggled(bool checked)
{
    Utils::setSwitchButtonBackground(passiveFlyAroundUi->switchSpeed,
                                     initialButtonSize,
                                     checked);
}

void Task_PassiveFlyAround::on_switchDirection_toggled(bool checked)
{
    Utils::setSwitchButtonBackground(passiveFlyAroundUi->switchDirection,
                                     initialButtonSize,
                                     checked);
}

void Task_PassiveFlyAround::on_switchThrowProjectiles_toggled(bool checked)
{
    Utils::setSwitchButtonBackground(passiveFlyAroundUi->switchThrowProjectiles,
                                     initialButtonSize,
                                     checked);
}

void Task_PassiveFlyAround::on_switchTeleporting_toggled(bool checked)
{
    Utils::setSwitchButtonBackground(passiveFlyAroundUi->switchTeleporting,
                                     initialButtonSize,
                                     checked);
}

void Task_PassiveFlyAround::on_switchReactiveEnvironment_toggled(bool checked)
{
    Utils::setSwitchButtonBackground(passiveFlyAroundUi->switchReactiveEnvironment,
                                     initialButtonSize,
                                     checked);
}
