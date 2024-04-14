#ifndef NODEEDITORPARTICLECOLOR_H
#define NODEEDITORPARTICLECOLOR_H

#include "nodeeditor.h"

class QPushButton;
class QColorDialog;

class NodeEditorParticleColor : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorParticleColor(QWidget *parent = nullptr);
    void resetEditor() override;

private:
    QPushButton *m_startColorButton;
    QPushButton *m_endColorButton;

    QPushButton *m_rgbCurveEditor;
    QPushButton *m_alphaCurveEditor;

    QColorDialog *m_startColorDialog;
    QColorDialog *m_endColorDialog;

private slots:
    void startColorChanged(const QColor &color);
    void endColorChanged(const QColor &color);

    void startColorButtonPressed();
    void endColorButtonPressed();
};

#endif // NODEEDITORPARTICLECOLOR_H
