#include "mainwindow.h"

#include <QHBoxLayout>
#include <QMenuBar>
#include <QJsonDocument>

#include "camera3d.h"
#include "viewport3d.h"
#include "contextnavigation3d.h"

#include "nodeviewer.h"
#include "nodeeditorfactory.h"

#include "glgrid.h"

MainWindow::MainWindow(QWidget *parent)
    : m_prevSelectedNodeId(-1),
    QMainWindow(parent)
{
    resize(1280, 720);

    m_nodesAndIds =
        {
            {"Life Time", 1},
            {"Emittions Rate", 2},
            {"Start Transformation", 3},
            {"Max Prticles", 4},
            {"Emitter Shape", 5},
            {"Force By Time", 6},
            {"Particle Speed", 7},
            {"Particle Rotation Speed", 8},
            {"Particle Size", 9},
            {"Particle Color", 10},
            {"Particle Trace", 11}
        };

    // untitled
    setWindowTitle(m_projectName.arg("untitled*"));

    // Central Widget
    m_centralWidget = new QWidget();
    setCentralWidget(m_centralWidget);

    // Central Layout
    m_centralLayout = new QHBoxLayout();
    m_centralWidget->setLayout(m_centralLayout);

    // Node Viewer
    m_nodeViewer = new NodeViewer(m_nodesAndIds);
    m_centralLayout->addWidget(m_nodeViewer);

    // 3D stuff
    m_camera3D = new Camera3D(QVector3D(0.0f, 0.0f, 0.0f), 45.0f);
    m_viewport3D = new Viewport3D(m_camera3D);
    m_contextNavigation3D = new ContextNavigation3D(m_viewport3D, m_camera3D);
    m_centralLayout->addWidget(m_viewport3D, 1);

    // Node Editors
    createNodeEditors();

    // Top Menu
    //setMenuBar(createTopMenu());

    QObject::connect(m_nodeViewer, &NodeViewer::nodeAdded, this, &MainWindow::nodeAdded);
    QObject::connect(m_nodeViewer, &NodeViewer::nodeRemoved, this, &MainWindow::nodeRemoved);
    QObject::connect(m_nodeViewer, &NodeViewer::nodeSelected, this, &MainWindow::nodeSelected);

    for (auto it = m_nodeEditors.begin(); it != m_nodeEditors.end(); ++it)
        QObject::connect(it.value(), &NodeEditor::nodeEditorWidgetChanged, this, &MainWindow::nodeEditorWidgetChanged);



    QMenuBar *menuBar = new QMenuBar(this);

    QMenu *fileMenu = menuBar->addMenu(tr("File"));

    QAction *saveAction = new QAction(tr("Save"), this);
    fileMenu->addAction(saveAction);

    QAction *loadAction = new QAction(tr("Load"), this);
    fileMenu->addAction(loadAction);

    setMenuBar(menuBar);

    QObject::connect(saveAction, &QAction::triggered, this, &MainWindow::saveToFile);
    QObject::connect(loadAction, &QAction::triggered, this, &MainWindow::loadFromFile);
}

MainWindow::~MainWindow()
{
    delete m_camera3D;
    m_camera3D = nullptr;

    delete m_contextNavigation3D;
    m_contextNavigation3D = nullptr;
}

void MainWindow::nodeAdded(int nodeId)
{
    qDebug() << "Node added:" << nodeId;
}

void MainWindow::nodeRemoved(int nodeId)
{
    qDebug() << "Node removed:" << nodeId;

    if (m_nodeEditors.contains(nodeId) && m_nodeEditors[nodeId])
        m_nodeEditors[nodeId]->resetEditor();
}

void MainWindow::nodeSelected(int nodeId)
{
    if ((nodeId == -1) && (m_prevSelectedNodeId != -1)) {
        m_nodeEditors[m_prevSelectedNodeId]->setVisible(false);
        m_prevSelectedNodeId = -1;
        return;
    }

    if (m_nodeEditors.contains(nodeId) && m_nodeEditors[nodeId] && (m_prevSelectedNodeId != nodeId))
        m_nodeEditors[nodeId]->setVisible(true);

    if ((m_prevSelectedNodeId != -1) && (m_prevSelectedNodeId != nodeId))
        m_nodeEditors[m_prevSelectedNodeId]->setVisible(false);

    m_prevSelectedNodeId = nodeId;
}

void MainWindow::nodeEditorWidgetChanged(const QString& name, QVariant param)
{
    qDebug() << name << param;
}

QMenuBar* MainWindow::createTopMenu()
{
    QMenuBar *menuBar = new QMenuBar(this);

    QMenu *fileMenu = menuBar->addMenu(tr("File"));

    QAction *saveAction = new QAction(tr("Save"), this);
    fileMenu->addAction(saveAction);

    QAction *loadAction = new QAction(tr("Load"), this);
    fileMenu->addAction(loadAction);

    return menuBar;
}

void MainWindow::createNodeEditors()
{
    foreach(const QString &name, m_nodesAndIds.keys())
    {
        const int nodeId = m_nodesAndIds[name];

        NodeEditor *m_editor = NodeEditorFactory::create(nodeId);

        if (m_editor) {
            m_nodeEditors.insert(nodeId, m_editor);
            m_centralLayout->addWidget(m_editor);
            m_editor->setVisible(false);
        }
    }
}

void MainWindow::saveToFile()
{
    QJsonObject nodeViewerStates = m_nodeViewer->serialize();

    QJsonObject nodeEditorsStates;
    for (auto it = m_nodeEditors.begin(); it != m_nodeEditors.end(); ++it)
        nodeEditorsStates[QString::number(it.key())] = it.value()->serialize();

    QJsonObject resultObject;
    resultObject["node_viewer"] = nodeViewerStates;
    resultObject["node_editors"] = nodeEditorsStates;

    QString filePath = "D:/output.json";
    saveJsonObject(resultObject, filePath);
}

void MainWindow::loadFromFile()
{
    QString filePath = "D:/output.json";
    QJsonObject resultObject = readJsonObjectFromFile(filePath);

    QJsonObject nodeViewerStates = resultObject["node_viewer"].toObject();
    QJsonObject nodeEditorsStates = resultObject["node_editors"].toObject();

    m_nodeViewer->deserialize(nodeViewerStates);

    for (auto it = nodeEditorsStates.constBegin(); it != nodeEditorsStates.constEnd(); ++it)
    {
        int nodeId = it.key().toInt();
        QJsonObject object = it.value().toObject();

        if (m_nodeEditors.contains(nodeId) && m_nodeEditors[nodeId])
            m_nodeEditors[nodeId]->deserialize(object);
    }
}

// TODO to utils

void MainWindow::saveJsonObject(const QJsonObject& jsonObject, const QString& filePath) {
    QJsonDocument jsonDoc(jsonObject);
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing: " << filePath;
        return;
    }
    file.write(jsonDoc.toJson());
    file.close();
    qDebug() << "JSON object saved to file: " << filePath;
}

QJsonObject MainWindow::readJsonObjectFromFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading: " << filePath;
        return QJsonObject();
    }

    QByteArray jsonData = file.readAll();
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &error);
    if (jsonDoc.isNull()) {
        qDebug() << "Failed to parse JSON data: " << error.errorString();
        return QJsonObject();
    }

    if (!jsonDoc.isObject()) {
        qDebug() << "JSON data is not an object";
        return QJsonObject();
    }

    return jsonDoc.object();
}
