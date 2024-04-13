#include "mainwindow.h"

#include <QHBoxLayout>
#include <QMenuBar>

#include "camera3d.h"
#include "viewport3d.h"
#include "contextnavigation3d.h"

#include "nodeviewer.h"

#include "glgrid.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(1280, 720);

    m_centralWidget = new QWidget();

    m_centralLayout = new QHBoxLayout();
    m_centralWidget->setLayout(m_centralLayout);

    m_nodeViewer = new NodeViewer();
    m_centralLayout->addWidget(m_nodeViewer);

    m_camera3D = new Camera3D(QVector3D(0.0f, 0.0f, 0.0f), 45.0f);
    m_viewport3D = new Viewport3D(m_camera3D);
    m_contextNavigation3D = new ContextNavigation3D(m_viewport3D, m_camera3D);
    m_centralLayout->addWidget(m_viewport3D, 1);

    setCentralWidget(m_centralWidget);

    // Create a top menu
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu *fileMenu = menuBar->addMenu(tr("File"));

    QAction *saveAction = new QAction(tr("Save"), this);
    fileMenu->addAction(saveAction);

    QAction *loadAction = new QAction(tr("Load"), this);
    fileMenu->addAction(loadAction);
}

MainWindow::~MainWindow()
{
    delete m_camera3D;
    m_camera3D = nullptr;

    delete m_contextNavigation3D;
    m_contextNavigation3D = nullptr;
}
