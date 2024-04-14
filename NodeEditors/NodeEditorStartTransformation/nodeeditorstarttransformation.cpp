#include "nodeeditorstarttransformation.h"

#include "../Vector2DEdit/vector2dedit.h"
#include "../FloatEdit/floatedit.h"

#include <QVector2D>

NodeEditorStartTransformation::NodeEditorStartTransformation(QWidget *parent) :
    NodeEditor(parent)
{
    m_velocity = new Vector2DEdit();
    m_velocity->setMaximum(-50.0f);
    m_velocity->setMaximum(50.0f);
    addItem(QString("Velocity:"), m_velocity);

    m_rotation = new FloatEdit();
    m_rotation->setRange(-180.0f, 180.0f);
    addItem(QString("Rotation:"), m_rotation);

    m_size = new FloatEdit();
    m_size->setRange(0.0f, 50.0f);
    addItem(QString("Scale:"), m_size);

    QObject::connect(m_velocity, &Vector2DEdit::valueChanged, this, &NodeEditorStartTransformation::valueVelocityChanged);
    QObject::connect(m_rotation, &FloatEdit::valueChanged, this, &NodeEditorStartTransformation::valueRotationChanged);
    QObject::connect(m_size, &FloatEdit::valueChanged, this, &NodeEditorStartTransformation::valueSizeChanged);
}

void NodeEditorStartTransformation::resetEditor()
{
    m_velocity->setValue(QVector2D(0.0f, 0.0f));
    m_rotation->setValue(0.0f);
    m_size->setValue(0.0f);
}

void NodeEditorStartTransformation::valueVelocityChanged()
{
    emit nodeEditorWidgetChanged(m_velocity->value());
}

void NodeEditorStartTransformation::valueRotationChanged(float value)
{
    emit nodeEditorWidgetChanged(value);
}

void NodeEditorStartTransformation::valueSizeChanged(float value)
{
    emit nodeEditorWidgetChanged(value);
}
