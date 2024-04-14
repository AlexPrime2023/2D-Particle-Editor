#include "nodeeditorforcebytime.h"

#include "../Vector2DEdit/vector2dedit.h"

#include <QPushButton>
#include <QVector2D>

NodeEditorForceByTime::NodeEditorForceByTime(QWidget *parent) :
    NodeEditor(parent)
{
    m_forceByTimeEdit = new Vector2DEdit();
    m_forceByTimeEdit->setMinimum(-50.0f);
    m_forceByTimeEdit->setMaximum(50.0f);
    addItem(QString("Force By Time:"), m_forceByTimeEdit);

    m_openCurveEditor = new QPushButton("Open Curve Editor");
    addItem(QString("Curve Editor:"), m_openCurveEditor);

    QObject::connect(m_forceByTimeEdit, &Vector2DEdit::valueChanged, this, &NodeEditorForceByTime::valueChanged);
}

void NodeEditorForceByTime::valueChanged()
{
    emit nodeEditorWidgetChanged(m_forceByTimeEdit->value());
}

void NodeEditorForceByTime::resetEditor()
{
    m_forceByTimeEdit->setValue(QVector2D(0.0f, 0.0f));
}
