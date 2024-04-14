#include "nodeeditoremittershape.h"

#include <QComboBox>

#include "../FloatEdit/floatedit.h"
#include "../Vector2DEdit/vector2dedit.h"
#include <QVector2D>

NodeEditorEmitterShape::NodeEditorEmitterShape(QWidget *parent) :
    NodeEditor(parent)
{
    m_shape = new QComboBox();
    m_shape->addItems({"Sphere", "Cone", "Edge"});
    addItem(QString("Emitter Shape:"), m_shape);

    m_position = new Vector2DEdit();
    m_position->setMinimum(-500.0f);
    m_position->setMaximum(500.0f);
    addItem(QString("Emitter Position:"), m_position);

    m_size = new FloatEdit();
    m_size->setRange(0.0f, 200.0f);
    addItem(QString("Emitter Size:"), m_size);

    QObject::connect(m_shape,SIGNAL(currentIndexChanged(int)),this,SLOT(valueEmitterShapeChanged(int)));
    QObject::connect(m_position, &Vector2DEdit::valueChanged, this, &NodeEditorEmitterShape::valueEmitterPositionChanged);
    QObject::connect(m_size, &FloatEdit::valueChanged, this, &NodeEditorEmitterShape::valueEmitterSizeChanged);
}

void NodeEditorEmitterShape::resetEditor()
{
    m_shape->setCurrentIndex(0);
    m_position->setValue(QVector2D(0.0f, 0.0f));
    m_size->setValue(0.0f);
}

void NodeEditorEmitterShape::valueEmitterShapeChanged(int value)
{
    emit nodeEditorWidgetChanged(value);
}

void NodeEditorEmitterShape::valueEmitterPositionChanged()
{
    emit nodeEditorWidgetChanged(m_position->value());
}

void NodeEditorEmitterShape::valueEmitterSizeChanged(float value)
{
    emit nodeEditorWidgetChanged(value);
}
