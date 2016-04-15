#ifndef TASK_PASSIVEFLYAROUND_H
#define TASK_PASSIVEFLYAROUND_H

#include <QWidget>

namespace Ui {
class Task_PassiveFlyAround;
}

class Task_PassiveFlyAround : public QWidget
{
    Q_OBJECT

public:
    explicit Task_PassiveFlyAround(QWidget *parent = 0);
    ~Task_PassiveFlyAround();

private:
    Ui::Task_PassiveFlyAround *ui;
};

#endif // TASK_PASSIVEFLYAROUND_H
