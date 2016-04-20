#include "task_passiveflyaround.h"
#include "ui_task_passiveflyaround.h"

Task_PassiveFlyAround::Task_PassiveFlyAround(QWidget *parent) :
    QWidget(parent),
    passiveFlyAroundUi(new Ui::Task_PassiveFlyAround)
{
    passiveFlyAroundUi->setupUi(this);
}

Task_PassiveFlyAround::~Task_PassiveFlyAround()
{
    delete passiveFlyAroundUi;
}
