#ifndef NODEVIEWER_H
#define NODEVIEWER_H

#include <QWidget>

class QListView;
class QStringListModel;
class QMouseEvent;
class QItemSelection;

class NodeViewer : public QWidget
{
    Q_OBJECT
public:
    NodeViewer(QHash<QString, int> nodesAndIds, QWidget *parent = nullptr);

signals:
    void nodeAdded(int nodeId);
    void nodeRemoved(int nodeId);
    void nodeSelected(int nodeId);

private slots:
    void showContextMenu(const QPoint &pos);
    void removeNode();
    void selectedNodeChanged(const QModelIndex &index);

private:
    QListView *m_listView;
    QStringListModel *m_model;

    QStringList m_nodeNames;

    QHash<QString, int> m_nodesAndIds;
};

#endif // NODEVIEWER_H
