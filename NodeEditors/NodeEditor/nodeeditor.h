#ifndef NODEEDITOR_H
#define NODEEDITOR_H

#include <QWidget>
#include <QVariant>

class QFormLayout;

class NodeEditor : public QWidget
{
    Q_OBJECT
public:
    virtual void resetEditor() = 0;

signals:
    void nodeEditorWidgetChanged(QVariant param);

protected:
    explicit NodeEditor(QWidget *parent = nullptr);
    void addItem(QString name, QWidget *widget, Qt::AlignmentFlag widgetAlignment = Qt::AlignBaseline);

protected:
    QFormLayout *m_layout;

private:
    void insertParam(int row, QString paramTitle, QWidget *widget, Qt::AlignmentFlag widgetAlignment = Qt::AlignBaseline);
};

#endif // NODEEDITOR_H
