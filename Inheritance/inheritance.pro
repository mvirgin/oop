QT += widgets
QT += multimedia

CONFIG += gui
CONFIG += c++14

HEADERS    = \
    Ghost.h \
    blinky.h \
    gameobject.h \
    inky.h \
    pinky.h \
    window.h \
    graphics.h \
    vec2d.h \
    vec3d.h \
    plugin.h \

SOURCES     = \
    Ghost.cpp \
    blinky.cpp \
    gameobject.cpp \
    inky.cpp \
    main.cpp \
    graphics.cpp \
    pinky.cpp \
    vec2d.cpp \
    vec3d.cpp \
    plugin.cpp \

DISTFILES += \
    notes.txt


