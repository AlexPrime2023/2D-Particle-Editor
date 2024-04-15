#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <QJsonObject>

class ISerializable {
public:
    virtual ~ISerializable() {}
    virtual QJsonObject serialize() const = 0;
    virtual void deserialize(const QJsonObject& object) = 0;
};

#endif // ISERIALIZABLE_H
