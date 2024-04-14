#include "nodeeditorparticlecolor.h"

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

    QObject::connect(m_startColorButton, &QPushButton::clicked, this, &NodeEditorParticleColor::startColorButtonPressed);
    QObject::connect(m_endColorButton, &QPushButton::clicked, this, &NodeEditorParticleColor::endColorButtonPressed);

    QObject::connect(m_startColorDialog, &QColorDialog::colorSelected, this, &NodeEditorParticleColor::startColorChanged);
    QObject::connect(m_endColorDialog, &QColorDialog::colorSelected, this, &NodeEditorParticleColor::endColorChanged);
}

void NodeEditorParticleColor::resetEditor()
{
    startColorChanged(QColor(Qt::red));
    endColorChanged(QColor(Qt::red));
}

void NodeEditorParticleColor::startColorChanged(const QColor &color)
{
    m_startColorButton->setStyleSheet(QString("background-color: %1").arg(color.name()));

    emit nodeEditorWidgetChanged(color);
}

void NodeEditorParticleColor::endColorChanged(const QColor &color)
{
    m_endColorButton->setStyleSheet(QString("background-color: %1").arg(color.name()));

    emit nodeEditorWidgetChanged(color);
}

void NodeEditorParticleColor::startColorButtonPressed()
{
    m_startColorDialog->show();
}

void NodeEditorParticleColor::endColorButtonPressed()
{
    m_endColorDialog->show();
}
