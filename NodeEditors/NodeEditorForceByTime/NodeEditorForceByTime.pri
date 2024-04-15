!NODE_EDITOR_FORCE_BY_TIME_PRI {

CONFIG += NODE_EDITOR_FORCE_BY_TIME_PRI

INCLUDEPATH += $$PWD

include($$PWD/../../Vector2DEdit/Vector2DEdit.pri)
include($$PWD/../../StringUtils/StringUtils.pri)

include($$PWD/../../CurveEditorDialog/CurveEditorDialog.pri)

HEADERS += \
    $$PWD/nodeeditorforcebytime.h

SOURCES += \
    $$PWD/nodeeditorforcebytime.cpp
}
