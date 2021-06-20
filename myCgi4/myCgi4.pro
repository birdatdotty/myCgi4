TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

include(../common.pri)
DEFINES += CONF=\\\"$${PREFIX}/etc/root.qml\\\"

target.path = $${PREFIX}/bin
QMAKE_LFLAGS_RPATH=
QMAKE_LFLAGS += "-Wl,-rpath,$${PREFIX}/lib"

LIBS += -L$$OUT_PWD/../ImportLib/ -lImportLib -ldl
LIBS += -L$$OUT_PWD/../confParser/ -lconfParser -ldl

INCLUDEPATH += $$PWD/../ImportLib
DEPENDPATH += $$PWD/../ImportLib

INCLUDEPATH += $$PWD/../confParser
DEPENDPATH += $$PWD/../confParser

INCLUDEPATH += $$PWD/../AbstractClasses
DEPENDPATH += $$PWD/../AbstractClasses

target.path = $${PREFIX}/bin
!isEmpty(target.path): INSTALLS += target
