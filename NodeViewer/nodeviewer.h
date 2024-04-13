#ifndef NODEVIEWER_H
#define NODEVIEWER_H

#include <QWidget>

class QListView;
class QStringListModel;

class NodeViewer : public QWidget
{
    Q_OBJECT
public:
    NodeViewer(QHash<QString, int> nodesAndIds, QWidget *parent = nullptr);

    // TODO Node Selected/Unselected
signals:
    void nodeAdded();
    void nodeRemoved();

private slots:
    void showContextMenu(const QPoint &pos);
    void removeNode();

private:
    QListView *m_listView;
    QStringListModel *m_model;

    QStringList m_nodeNames;

    QHash<QString, int> m_nodesAndIds;
};

#endif // NODEVIEWER_H
