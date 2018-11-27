TEMPLATE = app
TARGET = qtrgbledcontroller

macos:CONFIG -= app_bundle

CONFIG += c++11
QT += quick serialport

HEADERS += \
        rgbledcontroller.h

SOURCES += \
        main.cpp \
        rgbledcontroller.cpp

target.path = $$OUT_PWD/../bin
INSTALLS += target
