#ifndef TASK_OBJECTIVEFLYAROUND_H
#define TASK_OBJECTIVEFLYAROUND_H

#include <QWidget>

namespace Ui {
class Task_ObjectiveFlyAround;
}

class Task_ObjectiveFlyAround : public QWidget
{
    Q_OBJECT

public:
    explicit Task_ObjectiveFlyAround(QWidget *parent = 0);
    ~Task_ObjectiveFlyAround();

private:
    Ui::Task_ObjectiveFlyAround *objectiveFlyAroundUi;
    QString whiteBackground;
    QString transparentBackground;

    void readInStyleSheets();
};

#endif // TASK_OBJECTIVEFLYAROUND_H
