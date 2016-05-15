#ifndef TASK_PLATFORMHOPPERRIGHT_H
#define TASK_PLATFORMHOPPERRIGHT_H

#include <QWidget>
#include <QJsonObject>
#include <QString>
namespace Ui {
class Task_PlatformHopperRight;
}

class Task_PlatformHopperRight : public QWidget
{
    Q_OBJECT

public:
    explicit Task_PlatformHopperRight(QWidget *parent = 0);
    ~Task_PlatformHopperRight();
    void addValuesToJson(QJsonObject *json);
    void setValuesFromJson(QJsonObject json);

private:
    Ui::Task_PlatformHopperRight *rightPlatformHopperUi;
    QString whiteBackground;
    QString greenBackground;

    void readInStyleSheets();
};

#endif // TASK_PLATFORMHOPPERRIGHT_H
