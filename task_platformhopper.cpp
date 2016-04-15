#include "task_platformhopper.h"
#include "ui_task_platformhopper.h"

Task_PlatformHopper::Task_PlatformHopper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task_PlatformHopper)
{
    ui->setupUi(this);
}

Task_PlatformHopper::~Task_PlatformHopper()
{
    delete ui;
}
