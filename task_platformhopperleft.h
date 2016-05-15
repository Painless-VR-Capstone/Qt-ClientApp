#ifndef TASK_PLATFORMHOPPERLEFT_H
#define TASK_PLATFORMHOPPERLEFT_H

#include <QWidget>
#include <QJsonObject>
#include <QString>

namespace Ui {
class Task_PlatformHopperLeft;
}

class Task_PlatformHopperLeft : public QWidget
{
    Q_OBJECT

public:
    explicit Task_PlatformHopperLeft(QWidget *parent = 0);
    ~Task_PlatformHopperLeft();
    void setValuesFromJson(QJsonObject json);

private slots:
    void on_playerSpeedSpinBox_valueChanged(int arg1);

private:
    Ui::Task_PlatformHopperLeft *leftPlatformHopperUi;
    QString whiteBackground;
    QString greenBackground;

    void addValuesToJson(QJsonObject *json);
    int getPlayerObjectValue();
    void readInStyleSheets();
};

#endif // TASK_PLATFORMHOPPERLEFT_H
