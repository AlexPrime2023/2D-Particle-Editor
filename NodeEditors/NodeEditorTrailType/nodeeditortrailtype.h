#pragma once

#include "nodeeditor.h"

class QComboBox;

class NodeEditorTrailType : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorTrailType(QWidget *parent = nullptr);
    void resetEditor() override;

public:
    QJsonObject serialize() const override;
    void deserialize(const QJsonObject& object) override;

private slots:
    void trailTypeChanged(int value);

private:
    QComboBox *m_trailType;
};
