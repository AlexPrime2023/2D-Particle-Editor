#ifndef JSONFILEUTILS_H
#define JSONFILEUTILS_H

#include <QString>
#include <QVector2D>

namespace JsonFileUtils
{
    bool isSaveJsonObjectSuccessfully(const QJsonObject& jsonObject, const QString& filePath, QString &message);
    bool isReadJsonObjectFromFileSuccessfully(const QString& filePath, QJsonObject& jsonObject, QString &message);
}

#endif // JSONFILEUTILS_H
