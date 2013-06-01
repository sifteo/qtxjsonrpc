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
    QCOMPARE(message.idAsVariant(), QVariant());
    QCOMPARE(message.method(), QString(""));
    QVariantList params = message.parameters();
    QVERIFY(params.length() == 0);
}

void tst_JsonRpcMessage::setIdTest()
{
    JsonRpcMessage message;
    message.setId("abc123");
    QCOMPARE(message.id(), QString("abc123"));
    message.clearId();
    QCOMPARE(message.idAsVariant(), QVariant());
}

void tst_JsonRpcMessage::setMethodTest()
{
    JsonRpcMessage message;
    message.setMethod("echo");
    QCOMPARE(message.method(), QString("echo"));
}

void tst_JsonRpcMessage::addParameterTest()
{
    JsonRpcMessage message;
    message.addParameter("foo");
    message.addParameter("bar");
    QVariantList params = message.parameters();
    QVERIFY(params.length() == 2);
    QCOMPARE(params.at(0).toString(), QString("foo"));
    QCOMPARE(params.at(1).toString(), QString("bar"));
}


QTEST_APPLESS_MAIN(tst_JsonRpcMessage)
