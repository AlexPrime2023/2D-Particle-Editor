#include "nodeeditormaxparticles.h"

#include "../IntEdit/intedit.h"

#include <QDebug>

NodeEditorMaxParticles::NodeEditorMaxParticles(QWidget *parent) :
    NodeEditor(parent)
{
    m_maxParticles = new IntEdit();
    m_maxParticles->setRange(0, 1500);
    addItem(QString("Max Particles:"), m_maxParticles);

    QObject::connect(m_maxParticles, &IntEdit::valueChanged, this, &NodeEditorMaxParticles::valueMaxParticlesChanged);
}

void NodeEditorMaxParticles::resetEditor()
{
    m_maxParticles->setValue(0);
}

void NodeEditorMaxParticles::valueMaxParticlesChanged(int value)
{
    emit nodeEditorWidgetChanged(value);
}
