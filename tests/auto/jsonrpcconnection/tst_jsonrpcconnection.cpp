#include "tst_jsonrpcconnection.h"
#include <QtxMockCore>
#include <QtxJson>


void tst_JsonRpcConnection::initTestCase()
{
    qRegisterMetaType<JsonRpcMessage>("JsonRpcMessage");
}

void tst_JsonRpcConnection::cleanupTestCase()
{
}

void tst_JsonRpcConnection::init()
{
    mIODevice = 0;
    mConnection = 0;
    
    QTimer::singleShot(10000, this, SLOT(onTimeout()));
}

void tst_JsonRpcConnection::cleanup()
{
    if (mConnection) {
        delete mConnection;
        mConnection = 0;
    }
}

void tst_JsonRpcConnection::echoRequestTest()
{
    mIODevice = new MockIODevice("data/echoRequest.jsonrpc");
    mConnection = new JsonRpcConnection(mIODevice);
    connect(mConnection, SIGNAL(disconnected()), SLOT(onDisconnected()));
    
    QSignalSpy requestReceivedSpy(mConnection, SIGNAL(requestReceived(const JsonRpcMessage &)));
    QSignalSpy responseReceivedSpy(mConnection, SIGNAL(responseReceived(const JsonRpcMessage &)));
    QSignalSpy disconnectedSpy(mConnection, SIGNAL(disconnected()));
    QList<QVariant> arguments;
    
    mIODevice->open(QIODevice::ReadWrite);
    mEventLoop.exec();
    
    QVERIFY(requestReceivedSpy.count() == 1);
    QVERIFY(responseReceivedSpy.count() == 0);
    QVERIFY(disconnectedSpy.count() == 1);
    
    JsonRpcMessage request;
    arguments = requestReceivedSpy.takeFirst();
    request = arguments.at(0).value<JsonRpcMessage>();
    QCOMPARE(request.idAsVariant().toUInt(), (quint32)1);
    QCOMPARE(request.method(), QString("echo"));
    QVariantList params = request.parameters();
    QVERIFY(params.length() == 1);
    QCOMPARE(params.at(0).toString(), QString("Hello JSON-RPC"));
}

void tst_JsonRpcConnection::onDisconnected()
{
    mEventLoop.quit();
}

void tst_JsonRpcConnection::onTimeout()
{
    mEventLoop.quit();
}


QTEST_MAIN(tst_JsonRpcConnection)
