#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QHBoxLayout;
class QMenuBar;

class Camera3D;
class Viewport3D;
class ContextNavigation3D;

class NodeViewer;
class NodeEditor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *m_centralWidget;

    QHBoxLayout *m_centralLayout;

protected slots:
    void nodeAdded(int nodeId);
    void nodeRemoved(int nodeId);
    void nodeSelected(int nodeId);

private:
    QMenuBar* createTopMenu();
    void createNodeEditors();

private:
    Camera3D *m_camera3D;
    Viewport3D *m_viewport3D;
    ContextNavigation3D *m_contextNavigation3D;

private:
    QHash<QString, int> m_nodesAndIds;
    QHash<int, NodeEditor*> m_nodeEditors;

    int m_prevSelectedNodeId;

    QString m_projectName = "Particle Editor 2D (%1)";

private:
    NodeViewer *m_nodeViewer;
};
#endif // MAINWINDOW_H
