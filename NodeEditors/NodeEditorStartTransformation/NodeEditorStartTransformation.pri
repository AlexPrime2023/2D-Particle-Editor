!NODE_EDITOR_START_TRANSFORMATION_PRI {

CONFIG += NODE_EDITOR_START_TRANSFORMATION_PRI

INCLUDEPATH += $$PWD

include($$PWD/../../FloatEdit/FloatEdit.pri)
include($$PWD/../../Vector2DEdit/Vector2DEdit.pri)
include($$PWD/../../StringUtils/StringUtils.pri)

HEADERS += \
    $$PWD/nodeeditorstarttransformation.h

SOURCES += \
    $$PWD/nodeeditorstarttransformation.cpp
}
