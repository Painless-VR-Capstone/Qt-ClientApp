#include "visualtab.h"
#include "ui_visualtab.h"
#include <QString>

VisualTab::VisualTab(QWidget *parent) :
    QWidget(parent),
    visualTabUi(new Ui::VisualTab)
{
    visualTabUi->setupUi(this);
    visualTabUi->hueLabel->setText(QString::number(visualTabUi->hueSlider->value()));
    visualTabUi->saturationLabel->setText(QString::number(visualTabUi->saturationSlider->value()));
    visualTabUi->brightnessLabel->setText(QString::number(visualTabUi->brightnessSlider->value()));
    visualTabUi->contrastLabel->setText(QString::number(visualTabUi->contrastSlider->value()));
}

VisualTab::~VisualTab()
{
    delete visualTabUi;
}

void VisualTab::on_hueSlider_sliderMoved(int position)
{
    visualTabUi->hueLabel->setText(QString::number(position));
}

void VisualTab::on_saturationSlider_sliderMoved(int position)
{
    visualTabUi->saturationLabel->setText(QString::number(position));
}

void VisualTab::on_brightnessSlider_sliderMoved(int position)
{
    visualTabUi->brightnessLabel->setText(QString::number(position));
}

void VisualTab::on_contrastSlider_sliderMoved(int position)
{
    visualTabUi->contrastLabel->setText(QString::number(position));
}

void VisualTab::addValuesToJson(QJsonObject *json)
{
    json->insert("hue",visualTabUi->hueSlider->value() / (double) visualTabUi->hueSlider->maximum());
    json->insert("saturation", visualTabUi->saturationSlider->value() / (double) visualTabUi->saturationSlider->maximum());
    json->insert("brightness", visualTabUi->brightnessSlider->value() / (double) visualTabUi->brightnessSlider->maximum());
    json->insert("contrast", visualTabUi->contrastSlider->value() / (double) visualTabUi->contrastSlider->maximum());
}
