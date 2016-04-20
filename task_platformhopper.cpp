#include "task_platformhopper.h"
#include "ui_task_platformhopper.h"

Task_PlatformHopper::Task_PlatformHopper(QWidget *parent) :
    QWidget(parent),
    platformHopperUi(new Ui::Task_PlatformHopper)
{
    platformHopperUi->setupUi(this);
}

Task_PlatformHopper::~Task_PlatformHopper()
{
    delete platformHopperUi;
}
