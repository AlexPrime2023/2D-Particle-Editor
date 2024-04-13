#ifndef NODEVIEWER_H
#define NODEVIEWER_H

#include <QWidget>

#include <QListView>
#include <QStringListModel>

class NodeViewer : public QWidget
{
    Q_OBJECT
public:
    NodeViewer(QWidget *parent = nullptr);

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
};

#endif // NODEVIEWER_H
