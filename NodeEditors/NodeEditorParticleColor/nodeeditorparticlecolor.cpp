#include "nodeeditorparticlecolor.h"

#include "curveeditordialog.h"

#include <QPushButton>
#include <QPalette>

#include <QColorDialog>

NodeEditorParticleColor::NodeEditorParticleColor(QWidget *parent) :
    NodeEditor(parent)
{
    m_startColorButton = new QPushButton();
    m_startColorButton->setStyleSheet(QString("background-color: %1").arg(QColor(Qt::red).name()));
    addItem(QString("Start Color:"), m_startColorButton);

    m_endColorButton = new QPushButton();
    m_endColorButton->setStyleSheet(QString("background-color: %1").arg(QColor(Qt::red).name()));
    addItem(QString("End Color:"), m_endColorButton);

    m_rgbCurveEditor = new QPushButton("RGB");
    addItem(QString("RGB Curve Editor:"), m_rgbCurveEditor);

    m_alphaCurveEditor = new QPushButton("Alpha");
    addItem(QString("Alpha Curve Editor:"), m_alphaCurveEditor);

    m_startColorDialog = new QColorDialog();
    m_endColorDialog = new QColorDialog();

    m_curveEditorDialogRGB = new CurveEditorDialog();
    m_curveEditorDialogAlpha = new CurveEditorDialog();

    QObject::connect(m_startColorButton, &QPushButton::clicked, this, &NodeEditorParticleColor::startColorButtonPressed);
    QObject::connect(m_endColorButton, &QPushButton::clicked, this, &NodeEditorParticleColor::endColorButtonPressed);

    QObject::connect(m_startColorDialog, &QColorDialog::colorSelected, this, &NodeEditorParticleColor::startColorChanged);
    QObject::connect(m_endColorDialog, &QColorDialog::colorSelected, this, &NodeEditorParticleColor::endColorChanged);

    QObject::connect(m_rgbCurveEditor, &QPushButton::pressed, this, &NodeEditorParticleColor::curveEditorRGBButtonPressed);
    QObject::connect(m_alphaCurveEditor, &QPushButton::pressed, this, &NodeEditorParticleColor::curveEditorAlphaButtonPressed);
}

NodeEditorParticleColor::~NodeEditorParticleColor()
{
    delete m_curveEditorDialogRGB;
    m_curveEditorDialogRGB = nullptr;

    delete m_curveEditorDialogAlpha;
    m_curveEditorDialogAlpha = nullptr;
}

void NodeEditorParticleColor::curveEditorRGBButtonPressed()
{
    m_curveEditorDialogRGB->show();
}

void NodeEditorParticleColor::curveEditorAlphaButtonPressed()
{
    m_curveEditorDialogAlpha->show();
}

void NodeEditorParticleColor::resetEditor()
{
    startColorChanged(QColor(Qt::red));
    endColorChanged(QColor(Qt::red));
}

void NodeEditorParticleColor::startColorChanged(const QColor &color)
{
    m_startColorButton->setStyleSheet(QString("background-color: %1").arg(color.name()));
    m_startColor = color;

    emit nodeEditorWidgetChanged("Start Color", color);
}

void NodeEditorParticleColor::endColorChanged(const QColor &color)
{
    m_endColorButton->setStyleSheet(QString("background-color: %1").arg(color.name()));
    m_endColor = color;

    emit nodeEditorWidgetChanged("End Color", color);
}

void NodeEditorParticleColor::startColorButtonPressed()
{
    m_startColorDialog->show();
}

void NodeEditorParticleColor::endColorButtonPressed()
{
    m_endColorDialog->show();
}

QJsonObject NodeEditorParticleColor::serialize() const
{
    QJsonObject obj;
    obj["start_color"] = m_startColor.name();
    obj["end_color"] = m_endColor.name();
    return obj;
}

void NodeEditorParticleColor::deserialize(const QJsonObject& object)
{
    if (!object["start_color"].isNull())
        startColorChanged(QColor(object["start_color"].toString()));

    if (!object["end_color"].isNull())
        endColorChanged(QColor(object["end_color"].toString()));
}
