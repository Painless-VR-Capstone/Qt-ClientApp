#include "task_objectiveflyaround.h"
#include "ui_task_objectiveflyaround.h"
#include "utils.h"

Task_ObjectiveFlyAround::Task_ObjectiveFlyAround(QWidget *parent) :
    QWidget(parent),
    objectiveFlyAroundUi(new Ui::Task_ObjectiveFlyAround)
{
    objectiveFlyAroundUi->setupUi(this);
    readInStyleSheets();
//    objectiveFlyAroundUi->objectiveBox->setStyleSheet(whiteBackground);
//    Utils::giveWidgetShadow(objectiveFlyAroundUi->objectiveBox);
//    objectiveFlyAroundUi->scoringBox->setStyleSheet(transparentBackground);
//    objectiveFlyAroundUi->amountBox->setStyleSheet(transparentBackground);
//    objectiveFlyAroundUi->checkBox->setStyleSheet(transparentBackground);
//    objectiveFlyAroundUi->coinsBox->setStyleSheet(transparentBackground);
//    objectiveFlyAroundUi->difficultyBox->setStyleSheet(transparentBackground);
//    objectiveFlyAroundUi->enemyBox->setStyleSheet(transparentBackground);
//    objectiveFlyAroundUi->roundBox->setStyleSheet(transparentBackground);
//    objectiveFlyAroundUi->scoringBox->setStyleSheet(transparentBackground);
//    objectiveFlyAroundUi->timeLimitBox->setStyleSheet(transparentBackground);
//    objectiveFlyAroundUi->wallCollisionsBox->setStyleSheet(transparentBackground);
}

void Task_ObjectiveFlyAround::readInStyleSheets()
{
    whiteBackground = Utils::readInStyleSheet("task_options_background_white.style");
    transparentBackground = Utils::readInStyleSheet("transparent_background.style");
}

Task_ObjectiveFlyAround::~Task_ObjectiveFlyAround()
{
    delete objectiveFlyAroundUi;
}
