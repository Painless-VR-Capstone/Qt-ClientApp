#include "visualtab.h"
#include "ui_visualtab.h"
#include <QString>
#include <QColorDialog>
#include <QDebug>
#include "utils.h"

static const QString KEY_HUE = "hue";
static const QString KEY_CONTRAST = "contrast";
static const QString KEY_SATURATION = "saturation";
static const QString KEY_BRIGHTNESS = "brightness";
static const QString KEY_PLAYER = "playerColor";
static const QString KEY_HAZARD = "hazardColor";
static const QString KEY_WORLD = "worldColor";
static const QString KEY_OBJECTIVE = "objectiveColor";
static const QString KEY_CLOUD_NIGHT_SKY = "cloudNightSkyColor";
static const QString KEY_FOG_EXISTS = "fogExists";
static const QString KEY_FOG_DISTANCE = "fogDistance";
static const QString KEY_SKYBOX_EXISTS = "skyboxExists";

VisualTab::VisualTab(QWidget *parent) :
    QWidget(parent),
    visualTabUi(new Ui::VisualTab)
{
    visualTabUi->setupUi(this);
    readInStyleSheets();
    visualTabUi->colorOptionsBox->setStyleSheet(greenBackground);
    visualTabUi->environmentOptionsBox->setStyleSheet(greenBackground);
    Utils::giveWidgetShadow(visualTabUi->colorOptionsBox);
    Utils::giveWidgetShadow(visualTabUi->environmentOptionsBox);
    visualTabUi->colorOptionsInnerBox->setStyleSheet(whiteBackground);
    visualTabUi->environmentOptionsInnerBox->setStyleSheet(whiteBackground);
    visualTabUi->fogColorButton->setStyleSheet(greenButton);
    visualTabUi->hazardColorButton->setStyleSheet(greenButton);
    visualTabUi->nightCloudColorButton->setStyleSheet(greenButton);
    visualTabUi->objectiveColorButton->setStyleSheet(greenButton);
    visualTabUi->playerColorButton->setStyleSheet(greenButton);
    visualTabUi->worldColorButton->setStyleSheet(greenButton);
}

void VisualTab::readInStyleSheets()
{
    greenBackground = Utils::readInStyleSheet("task_options_background_green.style");
    whiteBackground = Utils::readInStyleSheet("task_options_background_white.style");
    greenButton = Utils::readInStyleSheet("task_button.style");
}

VisualTab::~VisualTab()
{
    delete visualTabUi;
}

void VisualTab::addValuesToJson(QJsonObject *json)
{
    json->insert(KEY_HUE, Utils::getJsonValueFromSlider(visualTabUi->hueSlider));
    json->insert(KEY_CONTRAST, Utils::getJsonValueFromSlider(visualTabUi->contrastSlider));
    json->insert(KEY_SATURATION, Utils::getJsonValueFromSlider(visualTabUi->saturationSlider));
    json->insert(KEY_BRIGHTNESS, Utils::getJsonValueFromSlider(visualTabUi->brightnessSlider));
    json->insert(KEY_PLAYER, Utils::getJsonValueForColor(playerColor));
    json->insert(KEY_HAZARD, Utils::getJsonValueForColor(hazardColor));
    json->insert(KEY_WORLD, Utils::getJsonValueForColor(worldColor));
    json->insert(KEY_OBJECTIVE, Utils::getJsonValueForColor(objectiveColor));
    json->insert(KEY_CLOUD_NIGHT_SKY, Utils::getJsonValueForColor(nightCloudColor));
    json->insert(KEY_FOG_EXISTS, visualTabUi->fogCheckBox->isChecked());
    json->insert(KEY_FOG_DISTANCE, Utils::getJsonValueFromSlider(visualTabUi->fogDistanceSlider));
    json->insert(KEY_SKYBOX_EXISTS, visualTabUi->skyBoxCheckBox->isChecked());

}

QColor VisualTab::getColorFromDialog()
{
    QColorDialog dialog(this);
    dialog.exec();
    QColor color = dialog.currentColor();
#ifndef DEBUG
    for(int i = 0; i < color.colorNames().length(); i++)
    {
        qDebug() << color.colorNames().at(i);
    }
#endif
    return color;
}

QString VisualTab::getStyleSheetForColor(QColor color)
{
    QString sheet;
    sheet.append("QPushButton {");
    sheet.append("    background-color: ").append(color.name()).append(";");
    sheet.append("    border-style: outset;");
    sheet.append("    border-width: 0px;");
    sheet.append("    border-radius: 6px;");
    sheet.append("    border-color:").append(color.name()).append(";");
    sheet.append("    min-width: 10em;");
    sheet.append("    padding: 6px;");
    sheet.append("}");
    qDebug() << sheet;
    return sheet;
}

void VisualTab::updateButtonFromColor(QPushButton *button, QColor color)
{
    button->setStyleSheet(getStyleSheetForColor(color));
    button->update();
}

void VisualTab::setButtonColor(QPushButton *button, QColor color)
{
    button->setStyleSheet(getStyleSheetForColor(color));
}

void VisualTab::on_playerColorButton_clicked()
{
    playerColor = getColorFromDialog();
    setButtonColor(visualTabUi->playerColorButton, playerColor);
}

void VisualTab::on_worldColorButton_clicked()
{
    worldColor = getColorFromDialog();
    setButtonColor(visualTabUi->worldColorButton, worldColor);
}

void VisualTab::on_hazardColorButton_clicked()
{
    hazardColor = getColorFromDialog();
    setButtonColor(visualTabUi->hazardColorButton, hazardColor);
}

void VisualTab::on_objectiveColorButton_clicked()
{
    objectiveColor = getColorFromDialog();
    setButtonColor(visualTabUi->objectiveColorButton, objectiveColor);
}

void VisualTab::on_fogColorButton_clicked()
{
    fogColor = getColorFromDialog();
    setButtonColor(visualTabUi->fogColorButton, fogColor);
}

void VisualTab::on_nightCloudColorButton_clicked()
{
    nightCloudColor = getColorFromDialog();
    setButtonColor(visualTabUi->nightCloudColorButton, nightCloudColor);
}

void VisualTab::setValuesFromJson(QJsonObject json)
{
    if (json.contains(KEY_HUE))
    {
        visualTabUi->hueSlider->setValue(
                    Utils::sliderValueForJsonValue(json.value(KEY_HUE).toDouble(),
                                                   visualTabUi->hueSlider)
                    );
    }
    if (json.contains(KEY_CONTRAST))
    {
        visualTabUi->hueSlider->setValue(
                    Utils::sliderValueForJsonValue(json.value(KEY_CONTRAST).toDouble(),
                                                   visualTabUi->hueSlider)
                    );
    }
    if (json.contains(KEY_SATURATION))
    {
        visualTabUi->hueSlider->setValue(
                    Utils::sliderValueForJsonValue(json.value(KEY_SATURATION).toDouble(),
                                                   visualTabUi->hueSlider)
                    );
    }
    if (json.contains(KEY_BRIGHTNESS))
    {
        visualTabUi->hueSlider->setValue(
                    Utils::sliderValueForJsonValue(json.value(KEY_BRIGHTNESS).toDouble(),
                                                   visualTabUi->hueSlider)
                    );
    }
    if (json.contains(KEY_FOG_DISTANCE))
    {
        visualTabUi->hueSlider->setValue(
                    Utils::sliderValueForJsonValue(json.value(KEY_HUE).toDouble(),
                                                   visualTabUi->hueSlider)
                    );
    }
    if (!json.value(KEY_PLAYER).toString("").compare(""))
    {
        playerColor = Utils::getColorFromRGBJsonValue(json.value(KEY_PLAYER));
        setButtonColor(visualTabUi->playerColorButton, playerColor);
    }
    if (!json.value(KEY_HAZARD).toString("").compare(""))
    {
        hazardColor = Utils::getColorFromRGBJsonValue(json.value(KEY_HAZARD));
        setButtonColor(visualTabUi->hazardColorButton, hazardColor);
    }
    if (!json.value(KEY_WORLD).toString("").compare(""))
    {
        worldColor = Utils::getColorFromRGBJsonValue(json.value(KEY_WORLD), true);
        setButtonColor(visualTabUi->worldColorButton, worldColor);
    }
    if (!json.value(KEY_OBJECTIVE).toString("").compare(""))
    {
        objectiveColor = Utils::getColorFromRGBJsonValue(json.value(KEY_OBJECTIVE));
        setButtonColor(visualTabUi->objectiveColorButton, objectiveColor);
    }
    if (!json.value(KEY_CLOUD_NIGHT_SKY).toString("").compare(""))
    {
        nightCloudColor = Utils::getColorFromRGBJsonValue(json.value(KEY_CLOUD_NIGHT_SKY));
        setButtonColor(visualTabUi->nightCloudColorButton, nightCloudColor);
    }
}
