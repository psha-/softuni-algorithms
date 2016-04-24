TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    sorter.cpp \
    sortablecollection.cpp \
    quicksorter.cpp

HEADERS += \
    sorter.h \
    sortablecollection.h \
    quicksorter.h

