QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Agregar recursos para incluir el archivo JSON
RESOURCES += resources.qrc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/ui/barrawindow.cpp \
    src/ui/cocinawindow.cpp \
    src/ui/poswindow.cpp \
    src/models/pedido.cpp \
    src/models/categoria.cpp \
    src/models/item.cpp \
    src/models/pedidoItem.cpp \
    src/main.cpp \
    src/models/menuloader.cpp


HEADERS += \
    src/ui/barrawindow.h \
    src/ui/cocinawindow.h \
    src/ui/poswindow.h \
    src/models/item.h \
    src/models/bebida.h \
    src/models/comida.h \
    src/models/categoria.h \
    src/models/pedido.h \
    src/models/pedidoItem.h \
    src/models/menuloader.h

FORMS += \
    src/ui/barrawindow.ui \
    src/ui/cocinawindow.ui \
    src/ui/poswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
