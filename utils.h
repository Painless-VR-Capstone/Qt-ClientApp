#ifndef UTILS_H
#define UTILS_H

#include <QJsonObject>


class Utils
{
public:
    // Takes the contents of the second QJsonObject and adds them to the
    // first QJsonObject
    static void mergeJsons(QJsonObject *json1, QJsonObject json2);
};

#endif // UTILS_H
