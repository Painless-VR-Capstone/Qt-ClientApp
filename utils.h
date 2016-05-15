#ifndef UTILS_H
#define UTILS_H

#include <QJsonObject>
#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include <QSlider>

class Utils
{
public:

    // Takes the contents of the second QJsonObject and adds them to the
    // first QJsonObject
    static void mergeJsons(QJsonObject *json1, QJsonObject json2);
    static QString readInStyleSheet(QString fileName);
    static void setEffectOnWidgetOnly(QWidget *w, QGraphicsDropShadowEffect *effect);
    static void giveWidgetShadow(QWidget *w, bool excludeChildren = true);
    static void makeButtonIntoSwitch(QPushButton *button,
                                     QSize initialButtonSize,
                                     QString switchStyleSheet = NULL,
                                     bool on = false);
    static void setSwitchButtonBackground(QPushButton *switchButton,
                                          QSize initialButtonSize,
                                          bool on);
    static QString getJsonValueForColor(QColor color);

    static double getJsonValueFromSlider(QSlider *slider);

    static int sliderValueForJsonValue(double jsonValue, QSlider *slider);

    static QColor getColorFromRGBJsonValue(QJsonValue value);

};

#endif // UTILS_H
