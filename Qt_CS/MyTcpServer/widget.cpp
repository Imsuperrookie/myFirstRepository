#include "mytcpserver.h"
#include <QListWidget>
#include <QLayout>
#include <QDebug>

MyTcpServer::MyTcpServer(QWidget *parent)
    : QWidget(parent)
{
    m_pConnectedClient = new QListWidget();
}

MyTcpServer::~MyTcpServer()
{

}
