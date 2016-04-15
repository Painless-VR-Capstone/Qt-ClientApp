#ifndef TASKTAB_H
#define TASKTAB_H

#include <QWidget>

namespace Ui {
class TaskTab;
}

class TaskTab : public QWidget
{
    Q_OBJECT

public:
    explicit TaskTab(QWidget *parent = 0);
    ~TaskTab();

private:
    Ui::TaskTab *ui;
};

#endif // TASKTAB_H
