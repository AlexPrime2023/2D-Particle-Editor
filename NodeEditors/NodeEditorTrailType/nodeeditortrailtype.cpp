#include "nodeeditortrailtype.h"

#include <QComboBox>

NodeEditorTrailType::NodeEditorTrailType(QWidget *parent) :
    NodeEditor(parent)
{
    m_trailType = new QComboBox();
    m_trailType->addItems({"None", "Trail", "Ribbon"});
    addItem(QString("Trail Type:"), m_trailType);

    QObject::connect(m_trailType,SIGNAL(currentIndexChanged(int)),this,SLOT(trailTypeChanged(int)));
}

void NodeEditorTrailType::resetEditor()
{
    m_trailType->setCurrentIndex(0);
}

void NodeEditorTrailType::onTrailTypeChanged(int value)
{
    emit nodeEditorWidgetChanged("Trail Type", value);
}

QJsonObject NodeEditorTrailType::serialize() const
{
    QJsonObject obj;
    obj["trail_type"] = m_trailType->currentIndex();
    return obj;
}

void NodeEditorTrailType::deserialize(const QJsonObject& object)
{
    if (!object["trail_type"].isNull())
        m_trailType->setCurrentIndex(object["trail_type"].toInt());
}
