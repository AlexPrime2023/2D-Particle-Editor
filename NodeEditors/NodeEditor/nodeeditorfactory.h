#ifndef NODEEDITORFACTORY_H
#define NODEEDITORFACTORY_H

#include <QWidget>

#include "nodeeditor.h"

class NodeEditorFactory
{
public:
    NodeEditorFactory() = delete;
    static NodeEditor *create(int editorNodeid, QWidget *parent = nullptr)
    {
        switch (editorNodeid)
        {
			return nullptr;
        }
    }
};

#endif // NODEEDITORFACTORY_H
