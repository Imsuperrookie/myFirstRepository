#include "qchatserver.h"
#include <QtNetwork>

QChatServer::QChatServer(QObject *parent)
    : QTcpServer(parent)
{

}

QChatServer::~QChatServer()
{

}

void QChatServer::incomingConnection(qintptr handle)
{

}

void QChatServer::startServer(int port)
{
    listen(QHostAddress::Any, port);
    emit serverStarted();
}
