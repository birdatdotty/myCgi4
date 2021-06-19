CONFIG -= qt

TEMPLATE = lib
CONFIG += c++11

HEADERS += \
    AOption.h \
    Bus.h \
    Page.h \
    Request.h \
    Server.h

# Default rules for deployment
isEmpty(PREFIX) {
  PREFIX = /opt/configParser2
}

headers.path    = $${PREFIX}/include
headers.files   += $$HEADERS
INSTALLS        += headers
