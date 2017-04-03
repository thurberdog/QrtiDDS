#
# QrtiDDS
#
# Author: Louis Meadows <lou@positivelyfrontstreet.com>
#
#

TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    qrtiddshandler.cpp \
    qrtidds.cpp \
    qrtiddslistener.cpp
HEADERS += \
    qrtiddshandler.h \
    qrtidds.h \
    qrtiddslistener.h
RESOURCES += qml.qrc
DEPENDPATH += $$PWD/../rti/ndds.5.2.3/include
DEPENDPATH += $$PWD/../rti/ndds.5.2.3/include/ndds
INCLUDEPATH += $$PWD/../rti/ndds.5.2.3/include
INCLUDEPATH += $$PWD/../rti/ndds.5.2.3/include/ndds
INCLUDEPATH += $$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lnddsc
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lnddscore
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lnddscpp
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lnddscpp2
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lnddscppz
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lnddstransporttcp
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lnddstransporttcpz
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lrticonnextmsgc
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lrticonnextmsgcpp
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lrticonnextmsgc
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lrtidlc
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lrtidlcpp
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lrtimonitoring
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lrtiroutingservice
LIBS += -L$$PWD/../rti/ndds.5.2.3/lib/x64Win64VS2015/ -lrtirsinfrastructure
LIBS += -lws2_32
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

QMAKE_CXXFLAGS += -DRTI_WIN32
QMAKE_CXXFLAGS += -DNDDS_DLL_VARIABLE

