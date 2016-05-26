#ifndef TASK_PASSIVEFLYAROUND_H
#define TASK_PASSIVEFLYAROUND_H

#include <QWidget>
#include <QJsonObject>
#include <QPushButton>
#include <QSlider>

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
    void addValuesToJson(QJsonObject *json);

private slots:
    void on_passiveSpeedLineEdit_editingFinished();

    void on_activeSpeedLineEdit_editingFinished();

private:
    Ui::Task_PassiveFlyAround *passiveFlyAroundUi;
    QString taskBackgroundGreenStyle;
    QString taskBackgroundWhiteStyle;
    QString transparentBackgroundStyle;
    ulong passiveSpeed;
    ulong activeSpeed;

    void readInStyleSheets();
    void setSwitchButtonBackground(QPushButton *button, bool on);
    void showNumberProblemBox();

};

#endif // TASK_PASSIVEFLYAROUND_H
