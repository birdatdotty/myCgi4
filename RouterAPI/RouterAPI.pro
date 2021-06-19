CONFIG -= qt
TEMPLATE = lib

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RouterAPI.cpp

HEADERS += \
    RouterAPI.h

INCLUDEPATH += $$PWD/../ImportLib
DEPENDPATH += $$PWD/../ImportLib
# Default rules for deployment.
include(../common.pri)

target.path = $${PREFIX}/lib
!isEmpty(target.path): INSTALLS += target

