#ifndef TASK_PLATFORMHOPPER_H
#define TASK_PLATFORMHOPPER_H

#include <QWidget>

namespace Ui {
class Task_PlatformHopper;
}

class Task_PlatformHopper : public QWidget
{
    Q_OBJECT

public:
    explicit Task_PlatformHopper(QWidget *parent = 0);
    ~Task_PlatformHopper();

private:
    Ui::Task_PlatformHopper *ui;
};

#endif // TASK_PLATFORMHOPPER_H
