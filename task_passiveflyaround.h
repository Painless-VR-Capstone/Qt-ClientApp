#ifndef TASK_PASSIVEFLYAROUND_H
#define TASK_PASSIVEFLYAROUND_H

#include <QWidget>
#include <QJsonObject>
#include <QPushButton>

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

private slots:
    void on_switchSpeed_toggled(bool checked);

    void on_switchDirection_toggled(bool checked);

    void on_switchThrowProjectiles_toggled(bool checked);

    void on_switchTeleporting_toggled(bool checked);

    void on_switchReactiveEnvironment_toggled(bool checked);

private:
    Ui::Task_PassiveFlyAround *passiveFlyAroundUi;
    QString taskBackgroundGreenStyle;
    QString taskBackgroundWhiteStyle;
    QString switchStyle;
    QSize initialButtonSize;

    void readInStyleSheets();
    void setSwitchButtonBackground(QPushButton *button, bool on);

};

#endif // TASK_PASSIVEFLYAROUND_H
