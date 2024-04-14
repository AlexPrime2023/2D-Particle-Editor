#include "nodeviewer.h"

#include <QListView>
#include <QStringListModel>

#include <QVBoxLayout>
#include <QMenu>

#include <QJsonArray>

NodeViewer::NodeViewer(QHash<QString, int> nodesAndIds, QWidget *parent) :
    m_nodesAndIds(nodesAndIds),
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    m_listView = new QListView(this);
    m_listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_listView, &QListView::customContextMenuRequested, this, &NodeViewer::showContextMenu);
    layout->addWidget(m_listView);

    m_model = new QStringListModel({}, this);
    m_listView->setModel(m_model);

    // Disable the ability to edit elements in the list
    m_listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QObject::connect(m_listView, &QListView::clicked, this, &NodeViewer::selectedNodeChanged);
}

void NodeViewer::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(tr("Context menu"), this);

    foreach (const QString &nodeName, m_nodesAndIds.keys()) {
        if (!m_model->stringList().contains(nodeName)) {
            QAction *addAction = contextMenu.addAction(nodeName);

            connect(addAction, &QAction::triggered, [this, nodeName]()
            {
                QStringList dataList = m_model->stringList();
                dataList.append(nodeName);
                m_model->setStringList(dataList);

                // Add the index of the new element
                // Set the current index in the view
                QModelIndex newIndex = m_model->index(dataList.count() - 1, 0);
                m_listView->setCurrentIndex(newIndex);

                emit nodeAdded(m_nodesAndIds[nodeName]);
                emit nodeSelected(m_nodesAndIds[nodeName]);
            });
        }
    }

    contextMenu.addSeparator();

    QAction removeAction(tr("Remove node"), this);
    connect(&removeAction, &QAction::triggered, this, &NodeViewer::removeNode);
    contextMenu.addAction(&removeAction);

    if (!m_model->rowCount())
        removeAction.setEnabled(false);

    contextMenu.exec(m_listView->mapToGlobal(pos));
}

void NodeViewer::removeNode()
{
    QModelIndexList selectedIndexes = m_listView->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty())
        return;

    const int index = selectedIndexes[0].row();

    emit nodeRemoved(m_nodesAndIds[m_model->stringList()[index]]);
    m_model->removeRow(index);

    const int currentSelection = m_listView->currentIndex().row();

    if (currentSelection != -1)
        emit nodeSelected(m_nodesAndIds[m_model->stringList()[currentSelection]]);
    else
        emit nodeSelected(currentSelection);
}

void NodeViewer::selectedNodeChanged(const QModelIndex &index)
{
    if (index.isValid()) {
        QString nodeName = m_model->stringList().at(index.row());
        emit nodeSelected(m_nodesAndIds.value(nodeName));
    }
}
