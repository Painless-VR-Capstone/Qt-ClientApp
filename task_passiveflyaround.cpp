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
#include <QMessageBox>

Task_PassiveFlyAround::Task_PassiveFlyAround(QWidget *parent) :
    QWidget(parent),
    passiveFlyAroundUi(new Ui::Task_PassiveFlyAround)
{
    passiveFlyAroundUi->setupUi(this);
    readInStyleSheets();
    passiveFlyAroundUi->lookBasedTurningRadioButton->setAutoExclusive(true);
    passiveFlyAroundUi->instantKeyboardRadioButton->setAutoExclusive(true);
    passiveFlyAroundUi->smoothKeyboardRadioButton->setAutoExclusive(true);
    passiveFlyAroundUi->flightBox->setStyleSheet(taskBackgroundGreenStyle);
    passiveFlyAroundUi->speedBox->setStyleSheet(taskBackgroundWhiteStyle);
    passiveFlyAroundUi->movementBox->setStyleSheet(taskBackgroundWhiteStyle);
    Utils::giveWidgetShadow(passiveFlyAroundUi->flightBox);
}

Task_PassiveFlyAround::~Task_PassiveFlyAround()
{
    delete passiveFlyAroundUi;
}

void Task_PassiveFlyAround::readInStyleSheets()
{
    taskBackgroundGreenStyle = Utils::readInStyleSheet("task_options_background_green.style");
    taskBackgroundWhiteStyle = Utils::readInStyleSheet("task_options_background_white.style");
    transparentBackgroundStyle = Utils::readInStyleSheet("transparent_background.style");

}

QJsonObject Task_PassiveFlyAround::getJsonObject()
{
    QJsonObject json;
    return json;
}

void Task_PassiveFlyAround::showNumberProblemBox()
{
    QMessageBox box;
    box.setText("Please enter a number.");
    box.exec();
}

void Task_PassiveFlyAround::on_passiveSpeedLineEdit_editingFinished()
{
    QString text = passiveFlyAroundUi->passiveSpeedLineEdit->text();
    if (text.isEmpty())
    {
        return;
    }
    bool ok;
    ulong speed = text.toULong(&ok);
    if (!ok)
    {
        showNumberProblemBox();
        passiveFlyAroundUi->passiveSpeedLineEdit->setFocus();
    }
    else
    {
        passiveSpeed = speed;
    }
}

void Task_PassiveFlyAround::on_activeSpeedLineEdit_editingFinished()
{
    QString text = passiveFlyAroundUi->passiveSpeedLineEdit->text();
    if (text.isEmpty())
    {
        return;
    }
    bool ok;
    ulong speed = text.toULong(&ok);
    if (!ok)
    {
        showNumberProblemBox();
        passiveFlyAroundUi->activeSpeedLineEdit->setFocus();
    }
    else
    {
        activeSpeed = speed;
    }
}

void Task_PassiveFlyAround::setValuesFromJson(QJsonObject json)
{

}
