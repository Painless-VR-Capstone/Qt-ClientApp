#include "task_objectiveflyaround.h"
#include "ui_task_objectiveflyaround.h"
#include "utils.h"

static const QString KEY_SHOW_USER_SCORE = "showUserScore";
static const QString KEY_SHOW_SCORE_ON_ROUND_END = "showScoreOnRoundEnd";
static const QString KEY_CAN_LOSE_ROUND = "loseRound";
static const QString KEY_TELEPORT_TO_START = "teleportToStart";
static const QString KEY_INCLUDE_TIME_LIMIT = "includeTimeLimit";
static const QString KEY_TIME_LIMIT = "timeLimit";
static const QString KEY_LOSE_IF_NO_COINS = "loseIfNoCoins";
static const QString KEY_NUMBER_OF_COINS_TO_LOSE = "numberOfCoinsToLose";
static const QString KEY_INCLUDE_ENEMIES = "includeEnemies";
static const QString KEY_ENEMIES_CHASE_PLAYER = "chasePlayer";
static const QString KEY_ENEMIES_SHOOT_PLAYER = "shootPlayer";
static const QString KEY_ENEMY_DIFFICULTY = "enemyDifficulty";
static const QString KEY_ENEMY_AMOUNT = "enemyAmount";

Task_ObjectiveFlyAround::Task_ObjectiveFlyAround(QWidget *parent) :
    QWidget(parent),
    objectiveFlyAroundUi(new Ui::Task_ObjectiveFlyAround)
{
    objectiveFlyAroundUi->setupUi(this);
    readInStyleSheets();
    objectiveFlyAroundUi->objectiveBox->setStyleSheet(greenBackground);
    Utils::giveWidgetShadow(objectiveFlyAroundUi->objectiveBox);
    objectiveFlyAroundUi->scoringBox->setStyleSheet(whiteBackground);
    objectiveFlyAroundUi->wallCollisionsBox->setStyleSheet(whiteBackground);
    objectiveFlyAroundUi->timeLimitBox->setStyleSheet(whiteBackground);
    objectiveFlyAroundUi->enemyBox->setStyleSheet(whiteBackground);
    objectiveFlyAroundUi->amountHighRadioButton->setAutoExclusive(true);
    objectiveFlyAroundUi->amountLowRadioButton->setAutoExclusive(true);
    objectiveFlyAroundUi->amountMediumRadioButton->setAutoExclusive(true);
    objectiveFlyAroundUi->difficultyEasyRadioButton->setAutoExclusive(true);
    objectiveFlyAroundUi->difficultyHardRadioButton->setAutoExclusive(true);
    objectiveFlyAroundUi->difficultyMediumRadioButton->setAutoExclusive(true);
}

void Task_ObjectiveFlyAround::readInStyleSheets()
{
    whiteBackground = Utils::readInStyleSheet("task_options_background_white.style");
    greenBackground = Utils::readInStyleSheet("task_options_background_green.style");
    transparentBackground = Utils::readInStyleSheet("transparent_background.style");
}

Task_ObjectiveFlyAround::~Task_ObjectiveFlyAround()
{
    delete objectiveFlyAroundUi;
}

void Task_ObjectiveFlyAround::addValuesToJson(QJsonObject *json)
{
    json->insert(KEY_SHOW_USER_SCORE, objectiveFlyAroundUi->userScoreCheckBox->isChecked());
    json->insert(KEY_SHOW_SCORE_ON_ROUND_END, objectiveFlyAroundUi->showScoreCheckBox->isChecked());
    json->insert(KEY_CAN_LOSE_ROUND, objectiveFlyAroundUi->loseRoundCheckBox->isChecked());
    json->insert(KEY_TELEPORT_TO_START, objectiveFlyAroundUi->teleportCheckBox->isChecked());
    json->insert(KEY_INCLUDE_TIME_LIMIT, objectiveFlyAroundUi->includeTimeCheckBox->isChecked());
    json->insert(KEY_LOSE_IF_NO_COINS, objectiveFlyAroundUi->loseIfNoCoins->isChecked());
    json->insert(KEY_INCLUDE_ENEMIES, objectiveFlyAroundUi->includeEnemiesCheckBox->isChecked());
    if (objectiveFlyAroundUi->includeTimeCheckBox->isChecked())
    {
        json->insert(KEY_TIME_LIMIT, objectiveFlyAroundUi->timeLimitSpinBox->value());
    }
    if (objectiveFlyAroundUi->loseIfNoCoins->isChecked())
    {
        json->insert(KEY_NUMBER_OF_COINS_TO_LOSE, objectiveFlyAroundUi->coinsSpinBox->value());
    }
    if (objectiveFlyAroundUi->includeEnemiesCheckBox->isChecked())
    {
        int diff = 1;
        if (objectiveFlyAroundUi->difficultyEasyRadioButton->isChecked())
        {
            json->insert(KEY_ENEMY_DIFFICULTY, 1);
        }
        else if (objectiveFlyAroundUi->difficultyMediumRadioButton->isChecked())
        {
            json->insert(KEY_ENEMY_DIFFICULTY, 2);
        }
        else if (objectiveFlyAroundUi->difficultyHardRadioButton->isChecked())
        {
            json->insert(KEY_ENEMY_DIFFICULTY, 3);
        }
        if (objectiveFlyAroundUi->amountLowRadioButton->isChecked())
        {
            json->insert(KEY_ENEMY_AMOUNT, 1);
        }
        else if (objectiveFlyAroundUi->amountMediumRadioButton->isChecked())
        {
            json->insert(KEY_ENEMY_AMOUNT, 2);
        }
        else if (objectiveFlyAroundUi->amountHighRadioButton->isChecked())
        {
            json->insert(KEY_ENEMY_AMOUNT, 3);
        }
        json->insert(KEY_ENEMIES_CHASE_PLAYER, objectiveFlyAroundUi->chaseCheckBox->isChecked());
        json->insert(KEY_ENEMIES_SHOOT_PLAYER, objectiveFlyAroundUi->shootCheckBox->isChecked());
    }
}

void Task_ObjectiveFlyAround::setValuesFromJson(QJsonObject json)
{

}

void Task_ObjectiveFlyAround::on_includeTimeCheckBox_toggled(bool checked)
{

}

void Task_ObjectiveFlyAround::on_loseIfNoCoins_toggled(bool checked)
{

}







































