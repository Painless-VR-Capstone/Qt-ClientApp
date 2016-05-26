#include "task_platformhopperleft.h"
#include "ui_task_platformhopperleft.h"
#include <QString>
#include "utils.h"

static const QString KEY_PLATFORM_SPEED = "platSpeed";
static const QString KEY_PLAYER_SPEED = "jumpSpeed";
static const QString KEY_PLATFORM_STREAM_WIDTH = "platStreamWidth";
static const QString KEY_PLAYER_OBJECT = "playerObject";
static const QString KEY_MULTIPLE_PATHS = "multiplePaths";

Task_PlatformHopperLeft::Task_PlatformHopperLeft(QWidget *parent) :
    QWidget(parent),
    leftPlatformHopperUi(new Ui::Task_PlatformHopperLeft)
{
    leftPlatformHopperUi->setupUi(this);
    leftPlatformHopperUi->bodyGirlRadioButton->setAutoExclusive(true);
    leftPlatformHopperUi->bodyGuyRadioButton->setAutoExclusive(true);
    leftPlatformHopperUi->bodyRobotRadioButton->setAutoExclusive(true);
    readInStyleSheets();
    leftPlatformHopperUi->platformBox->setStyleSheet(greenBackground);
    Utils::giveWidgetShadow(leftPlatformHopperUi->platformBox);
    leftPlatformHopperUi->platformSpeedBox->setStyleSheet(whiteBackground);
    leftPlatformHopperUi->pathsBox->setStyleSheet(whiteBackground);
    leftPlatformHopperUi->bodyBox->setStyleSheet(whiteBackground);
    leftPlatformHopperUi->playerSpeedBox->setStyleSheet(whiteBackground);
}

void Task_PlatformHopperLeft::addValuesToJson(QJsonObject *json)
{
    json->insert(KEY_PLATFORM_SPEED, leftPlatformHopperUi->playerSpeedSlider->value());
    json->insert(KEY_PLAYER_SPEED, leftPlatformHopperUi->playerSpeedSlider->value());
    json->insert(KEY_PLATFORM_STREAM_WIDTH, leftPlatformHopperUi->platformWidthSpinBox->value());
    json->insert(KEY_PLAYER_OBJECT, getPlayerObjectValue());
    if (leftPlatformHopperUi->multiplePathsCheckBox->isChecked())
    {
        json->insert(KEY_MULTIPLE_PATHS, 1);
    }
    else
    {

        json->insert(KEY_MULTIPLE_PATHS, 0);
    }
}

void Task_PlatformHopperLeft::readInStyleSheets()
{
    whiteBackground = Utils::readInStyleSheet("task_options_background_white.style");
    greenBackground = Utils::readInStyleSheet("task_options_background_green.style");
}

int Task_PlatformHopperLeft::getPlayerObjectValue()
{
    if (leftPlatformHopperUi->bodyGuyRadioButton->isChecked())
    {
        return 0;
    }
    else if (leftPlatformHopperUi->bodyGirlRadioButton->isChecked())
    {
        return 1;
    }
    else if (leftPlatformHopperUi->bodyRobotRadioButton->isChecked())
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

Task_PlatformHopperLeft::~Task_PlatformHopperLeft()
{
    delete leftPlatformHopperUi;
}

void Task_PlatformHopperLeft::on_playerSpeedSpinBox_valueChanged(int arg1)
{
}

void Task_PlatformHopperLeft::setValuesFromJson(QJsonObject json)
{

}
