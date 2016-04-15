#include "task_passiveflyaround.h"
#include "ui_task_passiveflyaround.h"

Task_PassiveFlyAround::Task_PassiveFlyAround(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task_PassiveFlyAround)
{
    ui->setupUi(this);
}

Task_PassiveFlyAround::~Task_PassiveFlyAround()
{
    delete ui;
}
