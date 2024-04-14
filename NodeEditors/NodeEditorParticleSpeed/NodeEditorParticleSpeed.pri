!NODE_EDITOR_PARTICLE_SPEED_PRI {

CONFIG += NODE_EDITOR_PARTICLE_SPEED_PRI

INCLUDEPATH += $$PWD

include($$PWD/../../FloatEdit/FloatEdit.pri)
include($$PWD/../../RandomFloatEdit/RandomFloatEdit.pri)

HEADERS += \
    $$PWD/nodeeditorparticlespeed.h

SOURCES += \
    $$PWD/nodeeditorparticlespeed.cpp
}
