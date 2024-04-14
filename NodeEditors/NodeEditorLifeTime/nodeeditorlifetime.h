#ifndef NODEEDITORLIFETIME_H
#define NODEEDITORLIFETIME_H

#include "nodeeditor.h"

class FloatEdit;
class RandomFloatEdit;

class NodeEditorLifeTime : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorLifeTime(QWidget *parent = nullptr);
    void resetEditor() override;

private:
    FloatEdit *m_floatEdit;
    RandomFloatEdit *m_randomFloatEdit;

private slots:
    void valueFloatEditChanged(float value);
    void valueFloatRandomEditChanged(float value);
};

#endif // NODEEDITORLIFETIME_H
