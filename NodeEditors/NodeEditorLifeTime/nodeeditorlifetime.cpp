#include "nodeeditorlifetime.h"

#include "../FloatEdit/floatedit.h"
#include "../RandomFloatEdit/randomfloatedit.h"

#include <QDebug>

NodeEditorLifeTime::NodeEditorLifeTime(QWidget *parent) :
    NodeEditor(parent)
{
    m_floatEdit = new FloatEdit;
    m_floatEdit->setRange(0.0f, 5.0f);
    addItem(QString("Life Time:"), m_floatEdit);

    m_randomFloatEdit = new RandomFloatEdit();
    m_randomFloatEdit->setRange(0.0f, 5.0f);
    addItem(QString("Life Time Random Range:"), m_randomFloatEdit);

    QObject::connect(m_floatEdit, &FloatEdit::valueChanged, this, &NodeEditorLifeTime::valueFloatEditChanged);
    QObject::connect(m_randomFloatEdit, &RandomFloatEdit::valueChanged, this, &NodeEditorLifeTime::valueFloatRandomEditChanged);
}

void NodeEditorLifeTime::resetEditor()
{
    m_floatEdit->setRange(0.0f, 5.0f);
    m_floatEdit->setValue(0.0f);

    m_randomFloatEdit->setRange(0.0f, 5.0f);
    m_floatEdit->setValue(0.0f);
}

void NodeEditorLifeTime::valueFloatEditChanged(float value)
{
    emit nodeEditorWidgetChanged(value);
}

void NodeEditorLifeTime::valueFloatRandomEditChanged(float value)
{
    m_floatEdit->setValue(value);
}

