QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        chgrp.cpp \
        exec.cpp \
        fdisk.cpp \
        listamount.cpp \
        login.cpp \
        loss.cpp \
        main.cpp \
        mkdisk.cpp \
        mkfs.cpp \
        mkgrp.cpp \
        mkusr.cpp \
        mount.cpp \
        nodomount.cpp \
        parser.cpp \
        rep.cpp \
        rmdisk.cpp \
        scanner.cpp \
        umount.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Proyecto1_201902663.pro.user \
    lexico.l \
    parser.y

HEADERS += \
    chgrp.h \
    estructura.h \
    exec.h \
    fdisk.h \
    listamount.h \
    login.h \
    loss.h \
    mkdisk.h \
    mkfs.h \
    mkgrp.h \
    mkusr.h \
    mount.h \
    nodomount.h \
    parser.h \
    rep.h \
    rmdisk.h \
    scanner.h \
    umount.h
