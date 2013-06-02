#ifndef TST_JSONRPCCONNECTION_H
#define TST_JSONRPCCONNECTION_H

#include "jsonrpcconnection.h"
#include <QtTest/QtTest>


Q_DECLARE_METATYPE(JsonRpcMessage)

class tst_JsonRpcConnection : public QObject
{
Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();
    
    void echoRequestTest();
    
private:
    QEventLoop mEventLoop;
    QIODevice *mIODevice;

    JsonRpcConnection *mConnection;
    
public slots:
    void onDisconnected();
    void onTimeout();
};

#endif // TST_JSONRPCCONNECTION_H
