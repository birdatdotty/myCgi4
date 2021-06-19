CONFIG -= qt

TEMPLATE = lib
DEFINES += SERVICE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Service.cpp

HEADERS += \
    Service.h

INCLUDEPATH += $$PWD/../ImportLib
DEPENDPATH += $$PWD/../ImportLib

INCLUDEPATH += $$PWD/../AbstractClasses
DEPENDPATH += $$PWD/../AbstractClasses

# Default rules for deployment.
isEmpty(PREFIX) {
  PREFIX = /opt/configParser2
}

target.path = $${PREFIX}/lib
!isEmpty(target.path): INSTALLS += target

