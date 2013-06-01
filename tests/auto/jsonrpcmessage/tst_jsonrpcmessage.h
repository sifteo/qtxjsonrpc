#ifndef TST_JSONRPCMESSAGE_H
#define TST_JSONRPCMESSAGE_H

#include "jsonrpcmessage.h"
#include <QtTest/QtTest>


class tst_JsonRpcMessage : public QObject
{
Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();
    
    void defaultConstructorTest();
};

#endif // TST_JSONRPCMESSAGE_H
