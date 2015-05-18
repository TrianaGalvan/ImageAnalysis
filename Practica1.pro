#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T14:38:16
#
#-------------------------------------------------

QT       += core gui

INCLUDEPATH += "../libs/armadillo-5.100.2/include/"

DEFINES += ARMA_DONT_USE_WRAPPER

LIBS += -llapack -lblas

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Practica1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mylabel.cpp \
    dlgimage.cpp \
    qcustomplot.cpp \
    histdialog.cpp \
    histogramadata.cpp \
    convolution.cpp \
    mascara.cpp

HEADERS  += mainwindow.h \
    dlgimage.h \
    mylabel.h \
    qcustomplot.h \
    histdialog.h \
    histogramadata.h \
    convolution.h \
    mascara.h

FORMS    += mainwindow.ui \
    dlgimage.ui \
    histdialog.ui \
    convolution.ui
