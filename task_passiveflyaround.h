#ifndef TASK_PASSIVEFLYAROUND_H
#define TASK_PASSIVEFLYAROUND_H

#include <QWidget>
#include <QJsonObject>

namespace Ui {
class Task_PassiveFlyAround;
}

class Task_PassiveFlyAround : public QWidget
{
    Q_OBJECT

public:
    explicit Task_PassiveFlyAround(QWidget *parent = 0);
    ~Task_PassiveFlyAround();
    QJsonObject getJsonObject();

private:
    Ui::Task_PassiveFlyAround *passiveFlyAroundUi;
};

#endif // TASK_PASSIVEFLYAROUND_H
