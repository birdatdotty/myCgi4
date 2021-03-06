#TEMPLATE = app
TEMPLATE = lib
CONFIG += staticlib

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


include(../common.pri)

DISTFILES += root.qml
DEFINES += CONF=\\\"$${PREFIX}/etc/root.qml\\\"

SOURCES += \
        Action.cpp \
        Command.cpp \
        ConfParser.cpp \
        Object.cpp \
        Option.cpp \
        Parser.cpp

HEADERS += \
    Action.h \
    Command.h \
    ConfParser.h \
    Object.h \
    Option.h \
    Parser.h \
    ParserData.h

conffile.files += root.qml
conffile.path = $${PREFIX}/etc
INSTALLS        += conffile

target.path = $${PREFIX}/bin
QMAKE_LFLAGS_RPATH=
QMAKE_LFLAGS += "-Wl,-rpath,$${PREFIX}/lib"

#LIBS += -L$$OUT_PWD/../ImportLib/ -lImportLib -ldl

INCLUDEPATH += $$PWD/../ImportLib
DEPENDPATH += $$PWD/../ImportLib

INCLUDEPATH += $$PWD/../AbstractClasses
DEPENDPATH += $$PWD/../AbstractClasses

#!isEmpty(target.path): INSTALLS += target
