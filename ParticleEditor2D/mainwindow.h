#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QHBoxLayout;

class Camera3D;
class Viewport3D;
class ContextNavigation3D;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *m_centralWidget;

    QHBoxLayout *m_centralLayout;

private:
    Camera3D *m_camera3D;
    Viewport3D *m_viewport3D;
    ContextNavigation3D *m_contextNavigation3D;
};
#endif // MAINWINDOW_H
