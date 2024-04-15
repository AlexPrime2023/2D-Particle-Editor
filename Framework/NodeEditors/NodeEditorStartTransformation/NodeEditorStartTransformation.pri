!NODE_EDITOR_START_TRANSFORMATION_PRI {

CONFIG += NODE_EDITOR_START_TRANSFORMATION_PRI

INCLUDEPATH += $$PWD

include($$PWD/../../Widgets/FloatEdit/FloatEdit.pri)
include($$PWD/../../Widgets/Vector2DEdit/Vector2DEdit.pri)

include($$PWD/../../Utils/StringUtils/StringUtils.pri)

HEADERS += \
    $$PWD/nodeeditorstarttransformation.h

SOURCES += \
    $$PWD/nodeeditorstarttransformation.cpp
}
