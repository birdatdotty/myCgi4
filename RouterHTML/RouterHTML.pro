CONFIG -= qt

TEMPLATE = lib
DEFINES += SERVICE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RouterHTML.cpp

HEADERS += \
    RouterHTML.h

INCLUDEPATH += $$PWD/../ImportLib
DEPENDPATH += $$PWD/../ImportLib
# Default rules for deployment.
isEmpty(PREFIX) {
  PREFIX = /opt/configParser2
}

target.path = $${PREFIX}/lib
!isEmpty(target.path): INSTALLS += target

