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
    void setValuesFromJson(QJsonObject json);
    void addValuesToJson(QJsonObject *json);

private slots:
    void on_includeTimeCheckBox_toggled(bool checked);

    void on_loseIfNoCoins_toggled(bool checked);

private:
    Ui::Task_ObjectiveFlyAround *objectiveFlyAroundUi;
    QString whiteBackground;
    QString transparentBackground;
    QString greenBackground;

    void readInStyleSheets();
};

#endif // TASK_OBJECTIVEFLYAROUND_H
