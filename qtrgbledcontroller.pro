TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS += src

qml.files = main.qml
qml.path = $$OUT_PWD
INSTALLS += qml

OTHER_FILES += $$files($$PWD/*.qml, true)
