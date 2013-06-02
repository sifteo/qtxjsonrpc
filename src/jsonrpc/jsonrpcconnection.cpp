#include "jsonrpcconnection.h"
#include "jsonrpcmessage.h"
#include <QtxJson>


JsonRpcConnection::JsonRpcConnection(QObject *parent /* = 0 */)
    : QObject(parent)
{
}

JsonRpcConnection::JsonRpcConnection(QIODevice *device, QObject *parent /* = 0 */)
    : QObject(parent),
      mIODevice(device)
{
    connect(mIODevice, SIGNAL(readyRead()), SLOT(onReadyRead()));
    connect(mIODevice, SIGNAL(aboutToClose()), SLOT(onAboutToClose()));
    
    mReader = new JsonReader(this);
    connect(mReader, SIGNAL(objectDecoded(const QHash<QString, QVariant> &)),
               this, SLOT(onObjectDecoded(const QHash<QString, QVariant> &)));
    //connect(mReader, SIGNAL(error(JsonReader::Error)),
    //           this, SLOT(onError(JsonReader::Error)));
}

JsonRpcConnection::~JsonRpcConnection()
{
}

void JsonRpcConnection::onReadyRead()
{
    QByteArray bytes = mIODevice->readAll();
    mReader->addData(bytes);
    mReader->parse();
}

void JsonRpcConnection::onAboutToClose()
{
    emit disconnected();
}
 
void JsonRpcConnection::onObjectDecoded(const QHash<QString, QVariant> & object)
{
    JsonRpcMessage message(object);
    
    emit requestReceived(message);
}
