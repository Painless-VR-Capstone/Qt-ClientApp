#ifndef VISUALTAB_H
#define VISUALTAB_H

#include <QWidget>
#include <QJsonObject>
#include <QPushButton>

namespace Ui {
class VisualTab;
}

class VisualTab : public QWidget
{
    Q_OBJECT

public:
    explicit VisualTab(QWidget *parent = 0);
    ~VisualTab();
    void addValuesToJson(QJsonObject *json);
    void setValuesFromJson(QJsonObject json);

private slots:

    void on_playerColorButton_clicked();

    void on_enemyColorButton_clicked();

    void on_hazardColorButton_clicked();

    void on_objectiveColorButton_clicked();

    void on_fogColorButton_clicked();

    void on_nightCloudColorButton_clicked();

    void on_worldColorButton_clicked();

private:
    Ui::VisualTab *visualTabUi;
    QColor playerColor;
    QColor worldColor;
    QColor uiColor;
    QColor hazardColor;
    QColor objectiveColor;
    QColor fogColor;
    QColor nightCloudColor;
    QString greenBackground;
    QString whiteBackground;
    QString greenButton;

    QColor getColorFromDialog();

    QString getStyleSheetForColor(QColor color);

    void updateButtonFromColor(QPushButton *button, QColor color);

    void readInStyleSheets();

    void setButtonColor(QPushButton *button, QColor color);

};

#endif // VISUALTAB_H
