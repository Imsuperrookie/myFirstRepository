#include "mytecpserver.h"
#include <QLabel>
#include <QLayout>
#include <QTcpServer>
#include <QHostAddress>
#include <QListWidget>
#include <QtNetwork>
#include <QDebug>

MyTecpServer::MyTecpServer(QWidget *parent)
    : QWidget(parent)
    , chater1(0)
    , chater2(0)
{
    m_pServerIpList = new QListWidget();
    m_pClientNameList = new QListWidget();

    QVBoxLayout *pBaseLayout = new QVBoxLayout(this);
    pBaseLayout->addWidget(m_pServerIpList);
    pBaseLayout->addWidget(m_pClientNameList);

    m_pServer = new QTcpServer(this);
    m_pServer->listen(QHostAddress::Any, 8081);

    connect(m_pServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    createServerIp();
}

MyTecpServer::~MyTecpServer()
{

}

void MyTecpServer::onNewConnection()
{
    /*
    qDebug() << "new connection...";
    m_pClientNameList->addItem("connect...");
    QTcpSocket *pClientConnectSocket = m_pServer->nextPendingConnection();

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);

    out << QString("server send msg....");

    pClientConnectSocket->write(block);
    if(!chater1)
        chater1 = pClientConnectSocket->socketDescriptor();
    else chater2 = pClientConnectSocket->socketDescriptor();
    */

    qDebug() << "new connection...";
    //m_pClientNameList->addItem("connect...");
    QTcpSocket *pClientConnectSocket = m_pServer->nextPendingConnection();
    m_ConnectedSocket.append(pClientConnectSocket);
    m_ConnectedClient.append(pClientConnectSocket->socketDescriptor());

    connect(pClientConnectSocket, SIGNAL(readyRead()), this, SLOT(onReceiveData()));
}

void MyTecpServer::onReceiveData()
{
    if(m_ConnectedSocket.length() > 1)
    {
        QDataStream in;
        in.setDevice(m_ConnectedSocket.at(0));
        in.startTransaction();
        QString data;
        in >> data;
        qDebug() << "Received data:" << data;

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out << data;
        m_ConnectedSocket.at(1)->write(block);
        in.abortTransaction();
    }
    else
    {
        QDataStream in;
        in.setDevice(m_ConnectedSocket.at(0));
        in.startTransaction();
        QString data;
        in >> data;
        qDebug() << "Received data:" << data;
        m_pClientNameList->addItem(QString("receice data from %1: %2").arg(m_ConnectedClient.at(0)).arg(data));
    }
}

void MyTecpServer::createServerIp()
{
    QList<QHostAddress> serverIpList = QNetworkInterface::allAddresses();
    for(int i=0; i<serverIpList.size(); ++i)
    {
        if(serverIpList.at(i) != QHostAddress::LocalHost &&
                serverIpList.at(i).toIPv4Address())
        {
            m_pServerIpList->addItem(serverIpList.at(i).toString());
            return;
        }
    }
}
