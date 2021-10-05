QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controls/stateui.cpp \
    Objects/agent.cpp \
    Objects/point.cpp \
    Objects/pvo.cpp \
    Objects/state.cpp \
    enviropment.cpp \
    logicwork.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Controls/stateui.h \
    Objects/agent.h \
    Objects/point.h \
    Objects/pvo.h \
    Objects/state.h \
    enviropment.h \
    logicwork.h \
    mainwindow.h

FORMS += \
    Controls/stateui.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
