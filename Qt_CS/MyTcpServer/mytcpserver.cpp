#include "mytcpserver.h"
#include "myserver.h"
#include <QtNetwork>
#include <QListWidget>
#include <QLayout>
#include <QDebug>

MyTcpServer::MyTcpServer(QWidget *parent)
    : QWidget(parent)
{
    m_pConnectedClient = new QListWidget(this);
    m_pConnectedClient->setFixedSize(320,480);

    m_pServer = new MyServer(this);
}

MyTcpServer::~MyTcpServer()
{

}

