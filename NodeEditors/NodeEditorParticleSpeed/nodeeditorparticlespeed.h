#ifndef NODEEDITORPARTICLESPEED_H
#define NODEEDITORPARTICLESPEED_H

#include "nodeeditor.h"

class FloatEdit;
class RandomFloatEdit;

class NodeEditorParticleSpeed : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorParticleSpeed(QWidget *parent = nullptr);
    void resetEditor() override;

private:
    FloatEdit *m_particleSpeed;
    RandomFloatEdit *m_randomParticleSpeed;

private slots:
    void valueFloatEditChanged(float value);
    void valueFloatRandomEditChanged(float value);
};

#endif // NODEEDITORPARTICLESPEED_H
