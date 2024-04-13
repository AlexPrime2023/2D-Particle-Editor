#ifndef NODEEDITOR_H
#define NODEEDITOR_H

#include <QWidget>

class QFormLayout;

class NodeEditor : public QWidget
{
    Q_OBJECT
public:
    explicit NodeEditor(QWidget *parent = nullptr);

protected:
    void addItem(QString name, QWidget *widget, Qt::AlignmentFlag widgetAlignment = Qt::AlignBaseline);

protected:
    QFormLayout *m_layout;

private:
    void insertParam(int row, QString paramTitle, QWidget *widget, Qt::AlignmentFlag widgetAlignment = Qt::AlignBaseline);
};

#endif // NODEEDITOR_H
