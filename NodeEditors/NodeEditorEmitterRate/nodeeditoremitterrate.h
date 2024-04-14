#ifndef NODEEDITOREMITTERRATE_H
#define NODEEDITOREMITTERRATE_H

#include "nodeeditor.h"

class IntEdit;

class NodeEditorEmitterRate : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorEmitterRate(QWidget *parent = nullptr);
    void resetEditor() override;

private slots:
    void valueChanged(int value);

private:
    IntEdit *m_intEdit;
};

#endif // NODEEDITOREMITTERRATE_H
