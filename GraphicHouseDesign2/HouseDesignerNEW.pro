QT += widgets
QT += multimedia

CONFIG += gui
CONFIG += c++14

HEADERS    = \
    house.h \
    room.h \
    wall.h \
    window.h \
    graphics.h \
    vec2d.h \
    vec3d.h \
    plugin.h \

SOURCES     = \
    house.cpp \
    main.cpp \
    graphics.cpp \
    vec2d.cpp \
    vec3d.cpp \
    plugin.cpp \

DISTFILES += \
    notes.txt


