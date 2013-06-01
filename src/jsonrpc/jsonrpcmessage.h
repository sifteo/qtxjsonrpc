#ifndef QTXJSONRPC_JSONRPCMESSAGE_H
#define QTXJSONRPC_JSONRPCMESSAGE_H

#include <QtCore>


class JsonRpcMessage : public QObject
{
Q_OBJECT
public:
    JsonRpcMessage(QObject *parent = 0);
    JsonRpcMessage(const QHash<QString, QVariant> & object, QObject *parent = 0);
    ~JsonRpcMessage();
    
    QString id() const;
    QVariant idAsVariant() const;
    QString method() const;
    QList<QVariant> parameters() const;
    
    void setId(const QString & id);
    void setIdToNull();
    void setMethod(const QString & method);
    void addParameter(const QVariant & value);
    
    bool isNotification() const;
    
    QString toString() const;

private:
    QHash<QString, QVariant> mObject;
};

#endif // QTXJSONRPC_JSONRPCMESSAGE_H
