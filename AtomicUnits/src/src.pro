TEMPLATE = lib
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
TARGET = atomic-units
Debug: QMAKE_CFLAGS += -DDEBUG

DEFINES += SRC_LIBRARY

SOURCES +=

HEADERS += \
    baseunits.h \
    compphysunits.h \
    atomicunits/audistance.h \
    atomicunits/atomicunits.h \
    atomicunits/autime.h
