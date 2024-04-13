#include "nodeviewer.h"

#include <QVBoxLayout>
#include <QMenu>
#include <QMouseEvent>

#include <QJsonArray>

NodeViewer::NodeViewer(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    m_listView = new QListView(this);
    m_listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_listView, &QListView::customContextMenuRequested, this, &NodeViewer::showContextMenu);
    layout->addWidget(m_listView);

    m_model = new QStringListModel({}, this);
    m_listView->setModel(m_model);

    m_nodeNames = QStringList({"Life Time", "Emittios Rate", "Start Transformation", "Max Prticles", "Emitter Shape", "Force By Time", "Particle Speed", "Particle Rotation Speed", "Particle Size", "Particle Color", "Particle Trace"});
}

void NodeViewer::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(tr("Context menu"), this);

    foreach (const QString &nodeName, m_nodeNames) {
        if (!m_model->stringList().contains(nodeName)) {
            QAction *addAction = contextMenu.addAction(nodeName);
            connect(addAction, &QAction::triggered, [this, nodeName]() {
                QStringList dataList = m_model->stringList();
                dataList.append(nodeName);
                m_model->setStringList(dataList);

                emit nodeAdded();
            });
        }
    }

    contextMenu.addSeparator();

    QAction removeAction(tr("Remove node"), this);
    connect(&removeAction, &QAction::triggered, this, &NodeViewer::removeNode);
    contextMenu.addAction(&removeAction);

    contextMenu.exec(m_listView->mapToGlobal(pos));
}

void NodeViewer::removeNode()
{
    QModelIndexList selectedIndexes = m_listView->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty())
        return;

    for (const QModelIndex &index : selectedIndexes) {
        m_model->removeRow(index.row());
    }

    emit nodeRemoved();
}
