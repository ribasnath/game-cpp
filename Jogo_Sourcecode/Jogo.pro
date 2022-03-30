QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    bullet.cpp \
    bulletdir.cpp \
    enemy.cpp \
    fofinho.cpp \
    fofinhocaiu.cpp \
    game.cpp \
    health.cpp \
    level.cpp \
    level2.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    resetgame.cpp \
    rino.cpp \
    score.cpp \
    slime.cpp \
    snail.cpp

HEADERS += \
    about.h \
    bullet.h \
    bulletdir.h \
    enemy.h \
    fofinho.h \
    fofinhocaiu.h \
    game.h \
    health.h \
    level.h \
    level2.h \
    mainwindow.h \
    player.h \
    resetgame.h \
    rino.h \
    score.h \
    slime.h \
    snail.h

FORMS += \
    about.ui \
    mainwindow.ui \
    resetgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

DISTFILES +=
