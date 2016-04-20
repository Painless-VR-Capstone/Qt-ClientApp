#ifndef VISUALTAB_H
#define VISUALTAB_H

#include <QWidget>
#include <QJsonObject>

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
    void on_hueSlider_sliderMoved(int position);

    void on_saturationSlider_sliderMoved(int position);

    void on_brightnessSlider_sliderMoved(int position);

    void on_contrastSlider_sliderMoved(int position);

private:
    Ui::VisualTab *visualTabUi;
};

#endif // VISUALTAB_H
