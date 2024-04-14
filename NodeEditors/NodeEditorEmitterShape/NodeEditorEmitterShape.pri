!NODE_EDITOR_EMITTER_SHAPE_PRI {

CONFIG += NODE_EDITOR_EMITTER_SHAPE_PRI

INCLUDEPATH += $$PWD

include($$PWD/../../Vector2DEdit/Vector2DEdit.pri)
include($$PWD/../../FloatEdit/FloatEdit.pri)

HEADERS += \
    $$PWD/nodeeditoremittershape.h

SOURCES += \
    $$PWD/nodeeditoremittershape.cpp
}
