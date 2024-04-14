#include "nodeeditoremitterrate.h"

#include "../IntEdit/intedit.h"

NodeEditorEmitterRate::NodeEditorEmitterRate(QWidget *parent) :
    NodeEditor(parent)
{
    m_intEdit = new IntEdit;
    m_intEdit->setRange(0, 150);
    addItem(QString("Emitter Rate:"), m_intEdit);

    QObject::connect(m_intEdit, &IntEdit::valueChanged, this, &NodeEditorEmitterRate::valueChanged);
}

void NodeEditorEmitterRate::valueChanged(int value)
{
    emit nodeEditorWidgetChanged(value);
}

void NodeEditorEmitterRate::resetEditor()
{
    m_intEdit->setRange(0, 150);
    m_intEdit->setValue(0);
}
