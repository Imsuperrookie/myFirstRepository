#include "myserver.h"
#include "connectrunnable.h"
#include "chatrunnable.h"
#include <QtNetwork>
#include <QDebug>

MyServer::MyServer(QObject *parent)
    : QTcpServer(parent)
{
    listen(QHostAddress::Any, 8081);

    m_pThreadPool = new QThreadPool(this);
}

MyServer::~MyServer()
{

}

void MyServer::incomingConnection(int descriptor)
{
    qDebug() << "new conntion...";
    ConnectRunnable *connectTask = new ConnectRunnable();
    connectTask->nSocketDescriptor = descriptor;

    connect(connectTask, SIGNAL(finished(int, QString)), this, SLOT(onNewConnection(int, QString)));

    m_pThreadPool->start(connectTask);
}

void MyServer::onNewConnection(int descriptor, QString id)
{
    qDebug() << id;
    QTcpSocket *pClientSocket = new QTcpSocket();
    pClientSocket->setSocketDescriptor(descriptor);
    UserInfo sUserInfo;
    sUserInfo.userID = id;
    sUserInfo.userSocket = pClientSocket;

    m_userInfo.append(sUserInfo);

    //客户端给客户端发送消息（经过服务器中转）
    connect(pClientSocket, SIGNAL(readyRead()), this, SLOT(sendDataToClient()));
}

void MyServer::sendDataToClient()
{
    qDebug() << "send data to client...";
    QTcpSocket *pSocket = static_cast<QTcpSocket *>(sender());

    QDataStream in;
    in.setDevice(pSocket);
    in.startTransaction();

    QString data;
    in >> data;
    qDebug() << data;

    ChatRunnable *pChatTask = new ChatRunnable();
    QString toClientID = data.mid(data.length()-3, 3);

    pChatTask->strMsg = data;
    for(int i=0; i<m_userInfo.length(); ++i)
    {
        if(m_userInfo.at(i).userID == toClientID)
        {
            pChatTask->nToClientSocketDescriptor =
                    m_userInfo.at(i).userSocket->socketDescriptor();
            break;
        }
    }

    m_pThreadPool->start(pChatTask);
}
