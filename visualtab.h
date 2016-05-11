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

private slots:

    void on_setThemeButton_clicked();

    void on_contrastSlider_sliderMoved(int position);

    void on_setMaterial1_clicked();

    void on_setMaterial2_clicked();

    void on_setMaterial3_clicked();

    void on_setMaterial4_clicked();

private:
    Ui::VisualTab *visualTabUi;

    QColor getColorFromDialog();

    QString getStyleSheetForColor(QColor color);

    void updateButtonFromColor(QPushButton *button, QColor color);

    QColor themeColor;
    QColor material1Color;
    QColor material2Color;
    QColor material3Color;
    QColor material4Color;
};

#endif // VISUALTAB_H
