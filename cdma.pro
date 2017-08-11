#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T21:56:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -LC:\mysql\lib -llibmysql
//LIBS += -lmysqlclient

TARGET = cdma
TEMPLATE = app
config += C++11

SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp \
    scriptdlg.cpp \
    my_sql.cpp

HEADERS  += mainwindow.h \
    logindlg.h \
    scriptdlg.h \
    my_sql.h
