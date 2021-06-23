CONFIG -= qt

TEMPLATE = lib
DEFINES += TESTLIB_LIBRARY

CONFIG += c++11

include(../common.pri)
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TestLib.cpp

HEADERS += \
    TestLib.h

INCLUDEPATH += $$PWD/../ImportLib
DEPENDPATH += $$PWD/../ImportLib
INCLUDEPATH += $$PWD/../AbstractClasses
DEPENDPATH += $$PWD/../AbstractClasses

# Default rules for deployment.

target.path = $${PREFIX}/lib
!isEmpty(target.path): INSTALLS += target

