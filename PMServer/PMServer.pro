#-------------------------------------------------
#
# Project created by QtCreator 2015-07-17T11:34:19
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = PMServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    pmnetworking.cpp \
    pmclient.cpp

HEADERS += \
    pmnetworking.h \
    pmclient.h
