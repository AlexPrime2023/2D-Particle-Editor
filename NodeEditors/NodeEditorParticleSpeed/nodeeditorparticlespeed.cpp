#include "nodeeditorparticlespeed.h"

#include "../FloatEdit/floatedit.h"
#include "../RandomFloatEdit/randomfloatedit.h"

NodeEditorParticleSpeed::NodeEditorParticleSpeed(QWidget *parent) :
    NodeEditor(parent)
{
    m_particleSpeed = new FloatEdit();
    m_particleSpeed->setRange(-50.0f, 50.0f);
    addItem(QString("Particle Speed:"), m_particleSpeed);

    m_randomParticleSpeed = new RandomFloatEdit();
    m_randomParticleSpeed->setRange(-50.0f, 50.0f);
    addItem(QString("Particle Speed Random Range:"), m_randomParticleSpeed);

    QObject::connect(m_particleSpeed, &FloatEdit::valueChanged, this, &NodeEditorParticleSpeed::valueFloatEditChanged);
    QObject::connect(m_randomParticleSpeed, &RandomFloatEdit::valueChanged, this, &NodeEditorParticleSpeed::valueFloatRandomEditChanged);
}

void NodeEditorParticleSpeed::resetEditor()
{
    m_particleSpeed->setRange(0.0f, 5.0f);
    m_particleSpeed->setValue(0.0f);

    m_randomParticleSpeed->setRange(0.0f, 5.0f);
    m_randomParticleSpeed->setValue(0.0f);
}

void NodeEditorParticleSpeed::valueFloatEditChanged(float value)
{
    emit nodeEditorWidgetChanged("Particle Speed", value);
}

void NodeEditorParticleSpeed::valueFloatRandomEditChanged(float value)
{
    m_particleSpeed->setValue(value);
}
