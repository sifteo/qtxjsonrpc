#include "tst_jsonrpcmessage.h"


void tst_JsonRpcMessage::initTestCase()
{
}

void tst_JsonRpcMessage::cleanupTestCase()
{
}

void tst_JsonRpcMessage::init()
{
}

void tst_JsonRpcMessage::cleanup()
{
}

void tst_JsonRpcMessage::defaultConstructorTest()
{
    JsonRpcMessage message;
    QCOMPARE(message.id(), QString(""));
}


QTEST_APPLESS_MAIN(tst_JsonRpcMessage)
