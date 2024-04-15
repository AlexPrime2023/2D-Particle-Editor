#ifndef NODEEDITORMAXPARTICLES_H
#define NODEEDITORMAXPARTICLES_H

#include "nodeeditor.h"

class IntEdit;

class NodeEditorMaxParticles : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorMaxParticles(QWidget *parent = nullptr);
    void resetEditor() override;

public:
    QJsonObject serialize() const override;
    void deserialize(const QJsonObject& object) override;

private:
    IntEdit *m_maxParticles;

private slots:
    void valueMaxParticlesChanged(int value);
};

#endif // NODEEDITORMAXPARTICLES_H
