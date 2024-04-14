#ifndef NODEEDITORTRAILTYPE_H
#define NODEEDITORTRAILTYPE_H

#include "nodeeditor.h"

class QComboBox;

class NodeEditorTrailType : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorTrailType(QWidget *parent = nullptr);
    void resetEditor() override;

private slots:
    void trailTypeChanged(int value);

private:
    QComboBox *m_trailType;
};

#endif // NODEEDITORTRAILTYPE_H
