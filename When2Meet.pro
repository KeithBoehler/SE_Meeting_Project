QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    Account.cpp \
    gui/Account.cpp \
    gui/loginwindow.cpp \
    gui/main.cpp \
    gui/mainwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    src/Account.cpp \
    src/Database.cpp \
    src/loginwindow.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/master.cpp

HEADERS += \
    Account.h \
    gui/Account.h \
    gui/loginwindow.h \
    gui/mainwindow.h \
    include/Account.h \
    include/Account_copy.h \
    include/Database.h \
    include/loginwindow.h \
    include/mainwindow.h \
    loginwindow.h \
    mainwindow.h

FORMS += \
    gui/loginwindow.ui \
    gui/mainwindow.ui \
    loginwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    gui/When2Meet.pro

DISTFILES += \
    gui/When2Meet.pro.user \
    gui/When2Meet.pro.user.c0a9e0e \
    src/Makefile
