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

static const QString ON_BUTTON_FILE_NAME = ":images/images/switch_on.png";
static const QString OFF_BUTTON_FILE_NAME = ":images/images/switch_off.png";

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
    setSwitchButtonBackground(passiveFlyAroundUi->switchDirection, false);
    setSwitchButtonBackground(passiveFlyAroundUi->switchReactiveEnvironment, false);
    setSwitchButtonBackground(passiveFlyAroundUi->switchSpeed, false);
    setSwitchButtonBackground(passiveFlyAroundUi->switchTeleporting, false);
    setSwitchButtonBackground(passiveFlyAroundUi->switchThrowProjectiles, false);
    passiveFlyAroundUi->switchDirection->setStyleSheet(switchStyle);
    passiveFlyAroundUi->switchReactiveEnvironment->setStyleSheet(switchStyle);
    passiveFlyAroundUi->switchSpeed->setStyleSheet(switchStyle);
    passiveFlyAroundUi->switchTeleporting->setStyleSheet(switchStyle);
    passiveFlyAroundUi->switchThrowProjectiles->setStyleSheet(switchStyle);
    passiveFlyAroundUi->switchDirection->setFocusPolicy(Qt::NoFocus);
    passiveFlyAroundUi->switchReactiveEnvironment->setFocusPolicy(Qt::NoFocus);
    passiveFlyAroundUi->switchSpeed->setFocusPolicy(Qt::NoFocus);
    passiveFlyAroundUi->switchTeleporting->setFocusPolicy(Qt::NoFocus);
    passiveFlyAroundUi->switchThrowProjectiles->setFocusPolicy(Qt::NoFocus);
}

void Task_PassiveFlyAround::setSwitchButtonBackground(QPushButton *button, bool on)
{
    QPixmap pixmap(on ? ON_BUTTON_FILE_NAME : OFF_BUTTON_FILE_NAME);
    QIcon icon(pixmap);
    button->setIcon(icon);
    QSize size = pixmap.size();
    int buttonHeight = qRound((initialButtonSize.height()) * 0.8);
    double ratio = ((double) size.width()) / size.height();
    int width = qRound(buttonHeight * ratio);
    button->setIconSize(QSize(width, buttonHeight));
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
    setSwitchButtonBackground(passiveFlyAroundUi->switchSpeed, checked);
}

void Task_PassiveFlyAround::on_switchDirection_toggled(bool checked)
{
    setSwitchButtonBackground(passiveFlyAroundUi->switchDirection, checked);
}

void Task_PassiveFlyAround::on_switchThrowProjectiles_toggled(bool checked)
{
    setSwitchButtonBackground(passiveFlyAroundUi->switchThrowProjectiles, checked);
}

void Task_PassiveFlyAround::on_switchTeleporting_toggled(bool checked)
{
    setSwitchButtonBackground(passiveFlyAroundUi->switchTeleporting, checked);
}

void Task_PassiveFlyAround::on_switchReactiveEnvironment_toggled(bool checked)
{
    setSwitchButtonBackground(passiveFlyAroundUi->switchReactiveEnvironment, checked);
}
