#include "jsonrpcmessage.h"
#include <QtxJson>


JsonRpcMessage::JsonRpcMessage()
{
}

JsonRpcMessage::JsonRpcMessage(const QHash<QString, QVariant> & object)
    : mObject(object)
{
}

JsonRpcMessage::~JsonRpcMessage()
{
}

QString JsonRpcMessage::id() const
{
    if (mObject.value("id").type() == QVariant::String) {
        return mObject.value("id").toString();
    } else if (mObject.value("id").type() == QVariant::LongLong) {
        return QString::number(mObject.value("id").toLongLong());
    }
    
    return "";
}

QVariant JsonRpcMessage::idAsVariant() const
{
    return mObject.value("id");
}

QString JsonRpcMessage::method() const
{
    if (mObject.value("method").type() == QVariant::String) {
        return mObject.value("method").toString();
    }
    
    return "";
}

QList<QVariant> JsonRpcMessage::parameters() const
{
    if (mObject.value("params").type() == QVariant::List) {
        return mObject.value("params").toList();
    }
    
    return QList<QVariant>();
}

QVariant JsonRpcMessage::result() const
{
    return mObject.value("result");
}

QVariant JsonRpcMessage::error() const
{
    return mObject.value("error");
}

void JsonRpcMessage::setId(const QString & id)
{
    mObject.insert("id", id);
}

void JsonRpcMessage::clearId()
{
    mObject.insert("id", QVariant());
}

void JsonRpcMessage::setMethod(const QString & method)
{
    mObject.insert("method", method);
}

void JsonRpcMessage::addParameter(const QVariant & value)
{
    if (mObject.contains("params")) {
        QList<QVariant> params = mObject.value("params").toList();
        params.append(value);
        mObject.insert("params", params);
    } else {
        QList<QVariant> params;
        params.append(value);
        mObject.insert("params", params);
    }
}

void JsonRpcMessage::setResult(const QVariant & value)
{
    mObject.insert("result", value);
}

void JsonRpcMessage::setError(const QVariant & value)
{
    mObject.insert("error", value);
}

bool JsonRpcMessage::isRequest() const
{
    if (isNotification()) {
        return false;
    }
    if (mObject.contains("method")) {
        return true;
    }
    return false;
}

bool JsonRpcMessage::isResponse() const
{
    if (isNotification()) {
        return false;
    }
    if (mObject.contains("result") || mObject.contains("error")) {
        return true;
    }
    return false;
}

bool JsonRpcMessage::isNotification() const
{
    if (!mObject.contains("id")) {
        return true;
    }
    if (mObject.value("id").isNull()) {
        return true;
    }
    
    return false;
}

QString JsonRpcMessage::toString() const
{
    return Json::stringify(mObject);
}
