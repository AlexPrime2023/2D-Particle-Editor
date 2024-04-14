#include "nodeeditorrotationspeed.h"

#include "../FloatEdit/floatedit.h"
#include "../RandomFloatEdit/randomfloatedit.h"

NodeEditorRotationSpeed::NodeEditorRotationSpeed(QWidget *parent) :
    NodeEditor(parent)
{
    m_rotationSpeed = new FloatEdit();
    m_rotationSpeed->setRange(-50.0f, 50.0f);
    addItem(QString("Particle Speed:"), m_rotationSpeed);

    m_randomRotationSpeed = new RandomFloatEdit();
    m_randomRotationSpeed->setRange(-50.0f, 50.0f);
    addItem(QString("Particle Speed Random Range:"), m_randomRotationSpeed);

    QObject::connect(m_rotationSpeed, &FloatEdit::valueChanged, this, &NodeEditorRotationSpeed::valueFloatEditChanged);
    QObject::connect(m_randomRotationSpeed, &RandomFloatEdit::valueChanged, this, &NodeEditorRotationSpeed::valueFloatRandomEditChanged);
}

void NodeEditorRotationSpeed::resetEditor()
{
    m_rotationSpeed->setRange(0.0f, 5.0f);
    m_rotationSpeed->setValue(0.0f);

    m_randomRotationSpeed->setRange(0.0f, 5.0f);
    m_randomRotationSpeed->setValue(0.0f);
}

void NodeEditorRotationSpeed::valueFloatEditChanged(float value)
{
    emit nodeEditorWidgetChanged("Particle Speed", value);
}

void NodeEditorRotationSpeed::valueFloatRandomEditChanged(float value)
{
    m_rotationSpeed->setValue(value);
}
