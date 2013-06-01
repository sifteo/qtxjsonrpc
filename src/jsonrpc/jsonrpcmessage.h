#ifndef QTXJSONRPC_JSONRPCMESSAGE_H
#define QTXJSONRPC_JSONRPCMESSAGE_H

#include <QtCore>


class JsonRpcMessage
{
public:
    JsonRpcMessage();
    JsonRpcMessage(const QHash<QString, QVariant> & object);
    ~JsonRpcMessage();
    
    QString id() const;
    QVariant idAsVariant() const;
    QString method() const;
    QList<QVariant> parameters() const;
    
    void setId(const QString & id);
    void clearId();
    void setMethod(const QString & method);
    void addParameter(const QVariant & value);
    
    bool isNotification() const;
    
    QString toString() const;

private:
    QHash<QString, QVariant> mObject;
};

#endif // QTXJSONRPC_JSONRPCMESSAGE_H
