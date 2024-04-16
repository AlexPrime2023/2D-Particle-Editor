# 2D Particle Editor

2D Particle Editor - небольшой редактор 2D частиц, написанный при помощи QtCreator. Он предназначени для редактирования партиклов из [этого репозитория](https://github.com/AlexPrime2023/2DParticleSystem).

[Видео демонстрация работы](https://youtu.be/NFT6fNV_AVk)

Редактор партиклов построен на системе Node. 

Node - конкретное свойство системы партикла - время жизни, например. У каждой Node есть свой NodeEditor, для задания различных характеристик.

### Описание GUI

Разделено на 3 области (NodeViewer (1), Viewport (2), NodeEditor (3)).
![Главное окно работы](https://github.com/AlexPrime2023/QtParticleEditor/assets/146464675/fa0f7dfb-70dc-42d3-b1ed-349cb7ebafba)

NodeViewer - виджет для управления нодами (добавление, выделение, удаление).
![NodeViewer](https://github.com/AlexPrime2023/QtParticleEditor/assets/146464675/b0602084-1440-49dc-8c98-da99d65a6387)

### Описание Viewport

CTRL + Right Mouse Button - поворот камеры
CTRL + Middle Mouse Button - panning камеры

### Добавление новой функциональности

Для добавления новой Node необходимо написать NodeEditor для редактирования ее свойства.

Для добавления новой ноды необходимо добавить ее название и номер в *NodeContainer*.

```cpp
NodeContainer::AddNodeToContainer("Life Time", 1);
```

Имя и номер должны быть уникальными, иначе не получится добавить.

Для добавления своего NodeEditor необходимо:
<ol>
    <li>
        Добавить CustomEditor в папку NodeEditors;
    </li>
    <li>
        Добавить CustomEditor.pri в NodeEditors.pri;
    </li>
    <li>
        Переопределить resetEditor() (вызывается при удалении Node из NodeViewer), serialize и deserialize, а также передать сигнал об изменении параметра <b>emit nodeEditorWidgetChanged("Life Time", value);</b>
    </li>
    <li>
        В файле NodeFacroty.h добавить в switch-case блок;
    </li>
</ol>

Node и NodeEditors готовы к использованию.

```h
class CustomNodeEditor : public NodeEditor
{
    Q_OBJECT
public:
    explicit CustomNodeEditor(QWidget *parent = nullptr);
    void resetEditor() override;

public:
    QJsonObject serialize() const override;
    void deserialize(const QJsonObject& object) override;
};
```

```h
class CustomNodeEditor : public NodeEditor
{
    Q_OBJECT
public:
    explicit CustomNodeEditor(QWidget *parent = nullptr);
    void resetEditor() override;

public:
    QJsonObject serialize() const override;
    void deserialize(const QJsonObject& object) override;
};
```

```cpp
CustomNodeEditor::CustomNodeEditor(QWidget *parent) :
    NodeEditor(parent)
{
    m_floatEdit = new FloatEdit;
    m_floatEdit->setRange(0.0f, 5.0f);
    addItem(QString("Custom Param:"), m_floatEdit);

    QObject::connect(m_floatEdit, &FloatEdit::valueChanged, this, &NodeEditorLifeTime::onValueFloatEditChanged);
}

void CustomNodeEditor::resetEditor()
{
    m_floatEdit->setRange(0.0f, 5.0f);
    m_floatEdit->setValue(0.0f);
}

void CustomNodeEditor::onValueFloatEditChanged(float value)
{
    emit nodeEditorWidgetChanged("Custom Param", value);
}
```

```cpp
    #include "nodeeditortcustom.h"

    case 12:
        return new CustomNode(parent);
```

### Недоработки (TODO)
<ul>
    <li>
        Разнести все по пространствам имен (namespace);
    </li>
    <li>
        Написать 2D Viewport (пока что только 3D подключен);
    </li>
    <li>
        Перейти от NodeId int -> enum class;
    </li>
    <li>
        Поправить фабрику создания NodeEditors;
    </li>
    <li>
        Нет интерполяции кривых (и они не уведомляют приложении об изименении их параметров);
    </li>
    <li>
        Нет Window->About (добавить о том, как пользоваться приложением приложением);
    </li>
    <li>
        Добавить 2D движок партиклов.
    </li>
</ul>
