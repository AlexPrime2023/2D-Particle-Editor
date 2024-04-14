#ifndef NODEEDITORFORCEBYTIME_H
#define NODEEDITORFORCEBYTIME_H

#include "nodeeditor.h"

class Vector2DEdit;
class QPushButton;

class NodeEditorForceByTime : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorForceByTime(QWidget *parent = nullptr);
    void resetEditor() override;

private slots:
    void valueChanged();

private:
    Vector2DEdit *m_forceByTimeEdit;
    QPushButton *m_openCurveEditor;
};

#endif // NODEEDITORFORCEBYTIME_H
