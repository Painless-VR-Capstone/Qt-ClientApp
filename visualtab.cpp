#include "visualtab.h"
#include "ui_visualtab.h"
#include <QString>
#include <QColorDialog>
#include <QDebug>
#include "utils.h"

VisualTab::VisualTab(QWidget *parent) :
    QWidget(parent),
    visualTabUi(new Ui::VisualTab)
{
    visualTabUi->setupUi(this);
    visualTabUi->colorPropertiesBox->setStyleSheet(
                Utils::readInStyleSheet("task_options_background_white.style"));
    Utils::giveWidgetShadow(visualTabUi->colorPropertiesBox);
    visualTabUi->sceneElementsBox->setStyleSheet(
                Utils::readInStyleSheet("task_options_background_white.style"));
    Utils::giveWidgetShadow(visualTabUi->sceneElementsBox);
    visualTabUi->userBodyComboBox->insertItem(0, "Human");
    visualTabUi->userBodyComboBox->insertItem(1, "Robot");
    visualTabUi->userBodyComboBox->insertItem(2, "Orb");
    visualTabUi->texturesComboBox->insertItem(0, "Flat");
    visualTabUi->texturesComboBox->insertItem(1, "Flat + Pattern");
    visualTabUi->texturesComboBox->insertItem(2, "Pbr");
}

VisualTab::~VisualTab()
{
    delete visualTabUi;
}

void VisualTab::addValuesToJson(QJsonObject *json)
{

}

void VisualTab::on_setThemeButton_clicked()
{
    QColor color = getColorFromDialog();
    themeColor = color;
    updateButtonFromColor(visualTabUi->setThemeButton, color);
}

void VisualTab::on_contrastSlider_sliderMoved(int position)
{

}

void VisualTab::on_setMaterial1_clicked()
{
    QColor color = getColorFromDialog();
    material1Color = color;
    updateButtonFromColor(visualTabUi->setMaterial1, color);

}

void VisualTab::on_setMaterial2_clicked()
{
    QColor color = getColorFromDialog();
    material2Color = color;
    updateButtonFromColor(visualTabUi->setMaterial2, color);

}

void VisualTab::on_setMaterial3_clicked()
{
    QColor color = getColorFromDialog();
    material3Color = color;
    updateButtonFromColor(visualTabUi->setMaterial3, color);
}

void VisualTab::on_setMaterial4_clicked()
{
    QColor color = getColorFromDialog();
    material4Color = color;
    updateButtonFromColor(visualTabUi->setMaterial4, color);
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
