!NODE_EDITOR_LIFE_TIME_PRI {

CONFIG += NODE_EDITOR_LIFE_TIME_PRI

INCLUDEPATH += $$PWD

include($$PWD/../../FloatEdit/FloatEdit.pri)
include($$PWD/../../RandomFloatEdit/RandomFloatEdit.pri)

HEADERS += \
    $$PWD/nodeeditorlifetime.h

SOURCES += \
    $$PWD/nodeeditorlifetime.cpp
}
