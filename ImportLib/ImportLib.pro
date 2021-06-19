CONFIG -= qt

TEMPLATE = lib
DEFINES += IMPORTLIB_LIBRARY

CONFIG += c++11

isEmpty(PREFIX) {
  PREFIX = /opt/configParser2
}
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ImportLib.cpp

HEADERS += \
    ImportLib.h

INCLUDEPATH += $$PWD/../AbstractClasses
DEPENDPATH += $$PWD/../AbstractClasses

# Default rules for deployment.
target.path = $${PREFIX}/lib

headers.path    = $${PREFIX}/include
headers.files   += $$HEADERS
INSTALLS       += headers

!isEmpty(target.path): INSTALLS += target
