#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>

class QThreadPool;

class MyServer : public QTcpServer
{
    Q_OBJECT

public:
    MyServer(QObject *parent = 0);
    ~MyServer();

    void incomingConnection(int descriptor) Q_DECL_OVERRIDE;

private slots:
    void onNewConnection(int descriptor, QString id);
    void sendDataToClient();

private:
    struct UserInfo
    {
        QTcpSocket *userSocket;
        QString userID;
    };

private:
    QThreadPool *m_pThreadPool;
//    QList<QTcpSocket *> m_ConnectedClientList;
    QList<UserInfo> m_userInfo;
    QTcpSocket *m_pClientSocket;
};

#endif // MYSERVER_H
