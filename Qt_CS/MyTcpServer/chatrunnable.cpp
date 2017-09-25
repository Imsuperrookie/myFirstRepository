#include "chatrunnable.h"
#include <QtNetwork>
#include <QDebug>

ChatRunnable::ChatRunnable(QObject *parent)
    : QObject(parent)
{

}

ChatRunnable::~ChatRunnable()
{

}

void ChatRunnable::run()
{
    if(!nToClientSocketDescriptor)
        return;

    m_pSocket = new QTcpSocket();
    m_pSocket->setSocketDescriptor(nToClientSocketDescriptor);

    QString strMsgContent;
    strMsgContent = strMsg.mid(3,strMsg.length() - 6);
    QByteArray data;
    QDataStream in(&data, QIODevice::WriteOnly);
    in << strMsgContent;

    m_pSocket->write(data);
    m_pSocket->flush();
}
