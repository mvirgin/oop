QT += widgets
QT += multimedia

CONFIG += gui
CONFIG += c++14

HEADERS    = \
    Ghost.h \
    blinky.h \
    clyde.h \
    gameobject.h \
    inky.h \
    maze.h \
    pacman.h \
    pinky.h \
    window.h \
    graphics.h \
    vec2d.h \
    vec3d.h \
    plugin.h \

SOURCES     = \
    Ghost.cpp \
    blinky.cpp \
    clyde.cpp \
    gameobject.cpp \
    inky.cpp \
    main.cpp \
    graphics.cpp \
    maze.cpp \
    pacman.cpp \
    pinky.cpp \
    vec2d.cpp \
    vec3d.cpp \
    plugin.cpp \

DISTFILES += \
    notes.txt


