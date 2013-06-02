#ifndef QTXJSONRPC_JSONRPCCONNECTION_H
#define QTXJSONRPC_JSONRPCCONNECTION_H

#include "jsonrpcmessage.h"
#include <QtCore>

class JsonReader;


class JsonRpcConnection : public QObject
{
    Q_OBJECT

public:
    JsonRpcConnection(QObject *parent = 0);
    JsonRpcConnection(QIODevice *device, QObject *parent = 0);
    ~JsonRpcConnection();
    
    //void connectToHost(const QString & hostName, quint16 port);

signals:
    void requestReceived(const JsonRpcMessage & message);
    void responseReceived(const JsonRpcMessage & message);
    void errorReceived(const JsonRpcMessage & message);
    void notificationReceived(const JsonRpcMessage & message);
    void disconnected();

private slots:
    void onReadyRead();
    void onAboutToClose();
    
    void onObjectDecoded(const QHash<QString, QVariant> & object);
    
private:
    QPointer<QIODevice> mIODevice;
    JsonReader* mReader;
};

#endif // JSONRPCCONNECTION_H
