#include "utils.h"
#include <QString>
#include <QStringList>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QWidget>
#include <QObjectList>

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
    qDebug() << fileName;
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
        qDebug() << "Getting the style sheet for task buttons didnt work";
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
