#ifndef NODEEDITORSTARTTRANSFORMATION_H
#define NODEEDITORSTARTTRANSFORMATION_H

#include "nodeeditor.h"

class Vector2DEdit;
class FloatEdit;
class QVector2D;

class NodeEditorStartTransformation : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorStartTransformation(QWidget *parent = nullptr);
    void resetEditor() override;

public:
    QJsonObject serialize() const override;
    void deserialize(const QJsonObject& object) override;

private:
    Vector2DEdit *m_velocity;
    FloatEdit *m_rotation;
    FloatEdit *m_size;

private slots:
    void valueVelocityChanged();
    void valueRotationChanged(float value);
    void valueSizeChanged(float value);
};

#endif // NODEEDITORSTARTTRANSFORMATION_H
