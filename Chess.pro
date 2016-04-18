#-------------------------------------------------
#
# Project created by QtCreator 2016-04-17T11:20:33
#
#-------------------------------------------------

QT       += core gui
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
    computer_intelligence-sima.cpp \
    computer_intelligence-yura.cpp \
    gui.cpp \
    possibilityofmove.cpp

HEADERS  += mainwindow.h \
    computer_intelligence.h
