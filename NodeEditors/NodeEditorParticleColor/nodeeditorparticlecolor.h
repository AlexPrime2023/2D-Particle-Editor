#ifndef NODEEDITORPARTICLECOLOR_H
#define NODEEDITORPARTICLECOLOR_H

#include "nodeeditor.h"

class QPushButton;
class QColorDialog;
class QColor;

class NodeEditorParticleColor : public NodeEditor
{
    Q_OBJECT
public:
    explicit NodeEditorParticleColor(QWidget *parent = nullptr);
    void resetEditor() override;

public:
    QJsonObject serialize() const override;
    void deserialize(const QJsonObject& object) override;

private:
    QPushButton *m_startColorButton;
    QPushButton *m_endColorButton;

    QPushButton *m_rgbCurveEditor;
    QPushButton *m_alphaCurveEditor;

    QColorDialog *m_startColorDialog;
    QColorDialog *m_endColorDialog;

    QColor m_startColor;
    QColor m_endColor;

private slots:
    void startColorChanged(const QColor &color);
    void endColorChanged(const QColor &color);

    void startColorButtonPressed();
    void endColorButtonPressed();
};

#endif // NODEEDITORPARTICLECOLOR_H
