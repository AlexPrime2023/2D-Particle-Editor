#ifndef NODEEDITORFORCEBYTIME_H
#define NODEEDITORFORCEBYTIME_H

#include "nodeeditor.h"

class Vector2DEdit;
class QPushButton;
class QCheckBox;

class NodeEditorForceByTime : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorForceByTime(QWidget *parent = nullptr);
    void resetEditor() override;

public:
    QJsonObject serialize() const override;
    void deserialize(const QJsonObject& object) override;

private slots:
    void valueChanged();
    void useCurveCheckBoxChanged(bool isUseCurve);

private:
    Vector2DEdit *m_forceByTimeEdit;
    QPushButton *m_openCurveEditor;
    QCheckBox *m_isUseCurve;
};

#endif // NODEEDITORFORCEBYTIME_H
