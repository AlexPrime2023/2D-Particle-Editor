#ifndef NODEEDITORROTATIONSPEED_H
#define NODEEDITORROTATIONSPEED_H

#include "nodeeditor.h"

class FloatEdit;
class RandomFloatEdit;

class NodeEditorRotationSpeed : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorRotationSpeed(QWidget *parent = nullptr);
    void resetEditor() override;

public:
    QJsonObject serialize() const override;
    void deserialize(const QJsonObject& object) override;

private:
    FloatEdit *m_rotationSpeed;
    RandomFloatEdit *m_randomRotationSpeed;

private slots:
    void valueFloatEditChanged(float value);
    void valueFloatRandomEditChanged(float value);
};

#endif // NODEEDITORROTATIONSPEED_H
