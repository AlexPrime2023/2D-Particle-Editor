#ifndef VIEW_H
#define VIEW_H

#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QSize>

struct View
{
    QMatrix4x4 projectionMatrix;
    QMatrix4x4 viewMatrix;

    QOpenGLFunctions *glFunction;

    QSize viewportSize;
};

#endif // VIEW_H
