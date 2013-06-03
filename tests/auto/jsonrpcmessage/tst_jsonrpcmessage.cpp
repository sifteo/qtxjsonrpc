#include "tst_jsonrpcmessage.h"
#include <QtxJson>


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
    QCOMPARE(message.result(), QVariant());
    QCOMPARE(message.error(), QVariant());
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

void tst_JsonRpcMessage::setResultTest()
{
    JsonRpcMessage message;
    message.setResult("foo bar");
    QCOMPARE(message.result().toString(), QString("foo bar"));
}

void tst_JsonRpcMessage::setErrorTest()
{
    JsonRpcMessage message;
    message.setError("something went wrong");
    QCOMPARE(message.error().toString(), QString("something went wrong"));
}

void tst_JsonRpcMessage::isRequestTest()
{
    JsonRpcMessage request;
    request.setId("1");
    request.setMethod("echo");
    request.addParameter("foo");
    QVERIFY(request.isRequest());
    
    JsonRpcMessage response;
    response.setId("1");
    response.setResult("echo");
    QVERIFY(!response.isRequest());
    
    JsonRpcMessage errResponse;
    errResponse.setId("1");
    errResponse.setError("something went wrong");
    QVERIFY(!errResponse.isRequest());
    
    JsonRpcMessage notification;
    notification.setMethod("echo");
    notification.addParameter("foo");
    QVERIFY(!notification.isRequest());
}

void tst_JsonRpcMessage::isResponseTest()
{
    JsonRpcMessage response;
    response.setId("1");
    response.setResult("echo");
    QVERIFY(response.isResponse());
    
    JsonRpcMessage errResponse;
    errResponse.setId("1");
    errResponse.setError("something went wrong");
    QVERIFY(errResponse.isResponse());
    
    JsonRpcMessage request;
    request.setId("1");
    request.setMethod("echo");
    request.addParameter("foo");
    QVERIFY(!request.isResponse());
    
    JsonRpcMessage notification;
    notification.setMethod("echo");
    notification.addParameter("foo");
    QVERIFY(!notification.isResponse());
}

void tst_JsonRpcMessage::isNotificationTest()
{
    JsonRpcMessage notification;
    notification.setMethod("echo");
    notification.addParameter("foo");
    QVERIFY(notification.isNotification());
    
    JsonRpcMessage request;
    request.setId("1");
    request.setMethod("echo");
    request.addParameter("foo");
    QVERIFY(!request.isNotification());
    
    JsonRpcMessage response;
    response.setId("1");
    response.setResult("echo");
    QVERIFY(!response.isNotification());
    
    JsonRpcMessage errResponse;
    errResponse.setId("1");
    errResponse.setError("something went wrong");
    QVERIFY(!errResponse.isNotification());
}

void tst_JsonRpcMessage::toStringTest()
{
    JsonRpcMessage request;
    request.setId("1");
    request.setMethod("echo");
    request.addParameter("foo");
    
    QString data = request.toString();
    
    QVariantHash json = Json::parse(data.toUtf8());
    QCOMPARE(json.value("id").toString(), QString("1"));
    QCOMPARE(json.value("method").toString(), QString("echo"));
    QVariantList params = json.value("params").toList();
    QVERIFY(params.length() == 1);
    QCOMPARE(params.at(0).toString(), QString("foo"));
}


QTEST_APPLESS_MAIN(tst_JsonRpcMessage)
