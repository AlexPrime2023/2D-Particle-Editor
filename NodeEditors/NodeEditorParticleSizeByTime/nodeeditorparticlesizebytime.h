#ifndef NODEEDITORPARTICLESIZEBYTIME_H
#define NODEEDITORPARTICLESIZEBYTIME_H

#include "nodeeditor.h"

class QPushButton;

class NodeEditorParticleSizeByTime : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorParticleSizeByTime(QWidget *parent = nullptr);
    void resetEditor() override;

private:
    QPushButton *m_openCurveEditor;
};

#endif // NODEEDITORPARTICLESIZEBYTIME_H
