#include "nodeeditorforcebytime.h"

#include "../Vector2DEdit/vector2dedit.h"

#include <QPushButton>
#include <QVector2D>
#include <QCheckBox>

NodeEditorForceByTime::NodeEditorForceByTime(QWidget *parent) :
    NodeEditor(parent)
{
    m_forceByTimeEdit = new Vector2DEdit();
    m_forceByTimeEdit->setMinimum(-50.0f);
    m_forceByTimeEdit->setMaximum(50.0f);
    addItem(QString("Force By Time:"), m_forceByTimeEdit);

    m_isUseCurve = new QCheckBox();
    addItem(QString("Use Curve:"), m_isUseCurve);

    m_openCurveEditor = new QPushButton("Open Curve Editor");
    addItem(QString("Curve Editor:"), m_openCurveEditor);

    QObject::connect(m_forceByTimeEdit, &Vector2DEdit::valueChanged, this, &NodeEditorForceByTime::valueChanged);
    QObject::connect(m_isUseCurve, &QCheckBox::clicked, this, &NodeEditorForceByTime::useCurveCheckBoxChanged);
}

void NodeEditorForceByTime::valueChanged()
{
    emit nodeEditorWidgetChanged("Force By Time", m_forceByTimeEdit->value());
}

void NodeEditorForceByTime::useCurveCheckBoxChanged(bool isUseCurve)
{
    m_forceByTimeEdit->setEnabled(!isUseCurve);
    emit nodeEditorWidgetChanged("Force By Time (curve)", QPointF());
}

void NodeEditorForceByTime::resetEditor()
{
    m_forceByTimeEdit->setValue(QVector2D(0.0f, 0.0f));
}
