#include "utils.h"
#include <QString>
#include <QStringList>

void Utils::mergeJsons(QJsonObject *json1, QJsonObject json2) {
    QStringList keys = json2.keys();
    for (int i = 0; i < keys.size(); i++)
    {
        json1->insert(keys.at(i), json2.find(keys.at(i)).value());
    }
}
