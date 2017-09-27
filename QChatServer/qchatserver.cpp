#include "qchatserver.h"
#include "connectserverrunnable.h"
#include <QtNetwork>
#include <QThreadPool>
#include <QDebug>

QChatServer::QChatServer(QObject *parent)
    : QTcpServer(parent)
    , m_pThreadPool(new QThreadPool)
{
    m_pThreadPool->setMaxThreadCount(15);
}

QChatServer::~QChatServer()
{

}

void QChatServer::incomingConnection(qintptr handle)
{
    ConnectServerRunnable *pConnectServer = new ConnectServerRunnable(this);
    pConnectServer->nClientSocket = handle;
    m_pThreadPool->start(pConnectServer);
    qDebug() << "new connection...";
}

void QChatServer::startServer(int port)
{
    listen(QHostAddress::Any, port);
    emit serverStarted();
}

void QChatServer::stopServer()
{
    close();
    emit serverStopped();
}
