TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += \
        bankir.cpp \
        kort.cpp \
        korthand.cpp \
        kortlek.cpp \
        main.cpp \
        minafunktioner.cpp \
        spelare.cpp

HEADERS += \
    bankir.h \
    kort.h \
    korthand.h \
    kortlek.h \
    minafunktioner.h \
    spelare.h

QT += widgets
