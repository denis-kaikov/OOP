QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractreader.cpp \
    bus.cpp \
    car.cpp \
    csvexception.cpp \
    csvreader.cpp \
    csvuploader.cpp \
    function.cpp \
    jsonreader.cpp \
    main.cpp \
    mainwindow.cpp \
    passenger.cpp \
    tbrowser.cpp \
    truck.cpp

HEADERS += \
    abstractreader.h \
    bus.h \
    car.h \
    csvexception.h \
    csvreader.h \
    csvuploader.h \
    function.h \
    jsonreader.h \
    mainwindow.h \
    passenger.h \
    tbrowser.h \
    truck.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
