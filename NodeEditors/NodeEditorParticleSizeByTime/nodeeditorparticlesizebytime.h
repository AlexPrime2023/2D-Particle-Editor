#pragma once

#include "nodeeditor.h"

class QPushButton;

class NodeEditorParticleSizeByTime : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorParticleSizeByTime(QWidget *parent = nullptr);
    void resetEditor() override;

public:
    QJsonObject serialize() const override;
    void deserialize(const QJsonObject& object) override;

private:
    QPushButton *m_openCurveEditor;
};
