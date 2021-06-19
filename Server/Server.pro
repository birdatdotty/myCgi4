CONFIG -= qt

TEMPLATE = lib
DEFINES += SERVER_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


HEADERS += \
    Server.h

INCLUDEPATH += $$PWD/../AbstractClasses
DEPENDPATH += $$PWD/../AbstractClasses

# Default rules for deployment.
isEmpty(PREFIX) {
  PREFIX = /opt/configParser2
}

headers.path    = $${PREFIX}/include
headers.files   += $$HEADERS
INSTALLS        += headers
