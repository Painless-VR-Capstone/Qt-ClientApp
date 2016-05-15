#include "utils.h"
#include <QString>
#include <QStringList>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QWidget>
#include <QObjectList>
#include <QJsonArray>

static const QString SWITCH_STYLE_FILE_NAME = "switch.style";
static const QString ON_BUTTON_FILE_NAME = ":images/images/switch_on.png";
static const QString OFF_BUTTON_FILE_NAME = ":images/images/switch_off.png";

static const double BUTTON_SIZE_REDUCTION_RATIO = 0.8;

void Utils::mergeJsons(QJsonObject *json1, QJsonObject json2) {
    QStringList keys = json2.keys();
    for (int i = 0; i < keys.size(); i++)
    {
        json1->insert(keys.at(i), json2.find(keys.at(i)).value());
    }
}

QString Utils::readInStyleSheet(QString fileName)
{
    fileName.insert(0, ":style/style/");
    QFile f(fileName);
#ifndef DEBUG
    qDebug() << "reading in style sheet at" << fileName;
#endif
    QString styleSheet;
    if (f.open(QIODevice::ReadOnly)) {
        QTextStream in(&f);
        styleSheet = in.readAll();
        return styleSheet;
    }
    else
    {
#ifndef DEBUG
        qDebug() << "Getting the style sheet didnt work";
#endif
        return NULL;
    }
}

void Utils::setEffectOnWidgetOnly(QWidget *w, QGraphicsDropShadowEffect *effect)
{
    w->setGraphicsEffect(effect);
    QObjectList children = w->children();
    for(int i = 0; i < children.length(); i++)
    {
        QWidget *child = (QWidget *) children.at(i);
        child->setGraphicsEffect(NULL);
    }
}

void Utils::giveWidgetShadow(QWidget *w, bool excludeChildren)
{
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(5);
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setColor(Qt::gray);
    if (excludeChildren)
    {
        Utils::setEffectOnWidgetOnly(w, effect);
    }
    else
    {
        w->setGraphicsEffect(effect);
    }
}

void Utils::makeButtonIntoSwitch(QPushButton *button,
                                 QSize initialButtonSize,
                                 QString switchStyleSheet,
                                 bool on)
{
    // Set Style Sheets
    if (switchStyleSheet == NULL)
    {
        switchStyleSheet = readInStyleSheet(SWITCH_STYLE_FILE_NAME);
    }
    button->setStyleSheet(switchStyleSheet);
    button->setFocusPolicy(Qt::NoFocus);
    Utils::setSwitchButtonBackground(button, initialButtonSize, on);
}

void Utils::setSwitchButtonBackground(QPushButton *switchButton,
                                   QSize initialButtonSize,
                                   bool on)
{
    QPixmap pixmap(on ? ON_BUTTON_FILE_NAME : OFF_BUTTON_FILE_NAME);
    QIcon icon(pixmap);
    switchButton->setIcon(icon);
    QSize size = pixmap.size();
    int buttonHeight = qRound((initialButtonSize.height()) * 0.8);
    double ratio = ((double) size.width()) / size.height();
    int width = qRound(buttonHeight * ratio);
    switchButton->setIconSize(QSize(width, buttonHeight));
}

QString Utils::getJsonValueForColor(QColor color)
{
    QString result("[");
    result.append(color.red())
          .append(", ")
          .append(color.green())
          .append(", ")
          .append(color.blue())
          .append("]");
    return result;

}

double Utils::getJsonValueFromSlider(QSlider *slider)
{
    return ((double) slider->value()) / slider->maximum();
}

int Utils::sliderValueForJsonValue(double jsonValue, QSlider *slider)
{
    return qRound(slider->maximum() * jsonValue);
}

QColor Utils::getColorFromRGBJsonValue(QJsonValue value)
{
    QJsonArray arr = value.toArray();
    int r = qRound(arr.at(0).toDouble() * 255);
    int g = qRound(arr.at(1).toDouble() * 255);
    int b = qRound(arr.at(2).toDouble() * 255);
    return QColor(r, g, b);
}











