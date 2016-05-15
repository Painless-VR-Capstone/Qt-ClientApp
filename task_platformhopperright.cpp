#include "task_platformhopperright.h"
#include "ui_task_platformhopperright.h"
#include "utils.h"

Task_PlatformHopperRight::Task_PlatformHopperRight(QWidget *parent) :
    QWidget(parent),
    rightPlatformHopperUi(new Ui::Task_PlatformHopperRight)
{
    rightPlatformHopperUi->setupUi(this);
    readInStyleSheets();
    rightPlatformHopperUi->bonuxBox->setStyleSheet(greenBackground);
    rightPlatformHopperUi->pickupsBox->setStyleSheet(whiteBackground);
    Utils::giveWidgetShadow(rightPlatformHopperUi->bonuxBox);
}

Task_PlatformHopperRight::~Task_PlatformHopperRight()
{
    delete rightPlatformHopperUi;
}

void Task_PlatformHopperRight::readInStyleSheets()
{
    whiteBackground = Utils::readInStyleSheet("task_options_background_white.style");
    greenBackground = Utils::readInStyleSheet("task_options_background_green.style");
}

void Task_PlatformHopperRight::addValuesToJson(QJsonObject *json)
{

}

void Task_PlatformHopperRight::setValuesFromJson(QJsonObject json)
{

}
