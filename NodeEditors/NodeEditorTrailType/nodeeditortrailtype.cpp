#include "nodeeditortrailtype.h"

#include <QComboBox>

NodeEditorTrailType::NodeEditorTrailType(QWidget *parent) :
    NodeEditor(parent)
{
    m_trailType = new QComboBox();
    m_trailType->addItems({"None", "Trail", "Ribbon"});
    addItem(QString("Particle Speed:"), m_trailType);

    QObject::connect(m_trailType,SIGNAL(currentIndexChanged(int)),this,SLOT(trailTypeChanged(int)));
}

void NodeEditorTrailType::resetEditor()
{
    m_trailType->setCurrentIndex(0);
}

void NodeEditorTrailType::trailTypeChanged(int value)
{
    emit nodeEditorWidgetChanged(value);
}
