TEMPLATE = app
TARGET = tst_jsonrpcmessage

QT += testlib
macx:CONFIG -= app_bundle

include(../../../mkspecs/test.pri)

HEADERS += tst_jsonrpcmessage.h
SOURCES += tst_jsonrpcmessage.cpp
