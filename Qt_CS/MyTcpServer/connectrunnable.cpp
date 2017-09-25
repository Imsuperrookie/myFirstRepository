#include "connectrunnable.h"
#include <QtNetwork>
#include <QDebug>

ConnectRunnable::ConnectRunnable(QObject *parent)
    : QObject(parent)
    , nSocketDescriptor(0)
{
    setAutoDelete(true);
}

ConnectRunnable::~ConnectRunnable()
{

}

void ConnectRunnable::run()
{
    if(!nSocketDescriptor)
        return;

    m_pSocket = new QTcpSocket();
    m_pSocket->setSocketDescriptor(nSocketDescriptor);

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);

    out << QString("Connect Server Successfully!");

    m_pSocket->write(data);
    m_pSocket->flush();
    //m_pSocket->waitForReadyRead();

    //获取用户的ID
    if(m_pSocket->waitForReadyRead())
    {
        QString id;
        QDataStream in;
        in.setDevice(m_pSocket);
        in.startTransaction();
        in >> id;
        qDebug() << "id:" << id;

        emit finished(nSocketDescriptor, id);
    }
}
