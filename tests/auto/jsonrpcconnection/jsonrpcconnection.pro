TEMPLATE = app
TARGET = tst_jsonrpcconnection

QT += testlib
macx:CONFIG -= app_bundle

include(../../../mkspecs/test.pri)

HEADERS += tst_jsonrpcconnection.h
SOURCES += tst_jsonrpcconnection.cpp
