#ifndef MYTECPSERVER_H
#define MYTECPSERVER_H

#include <QWidget>
#include <QThreadPool>

class QLabel;
class QTcpServer;
class QTcpSocket;
class QListWidget;
class MyTecpServer : public QWidget
{
    Q_OBJECT

public:
    MyTecpServer(QWidget *parent = 0);
    ~MyTecpServer();

private slots:
    void onNewConnection();
    void onReceiveData();

private:
    void createServerIp();

private:
    QListWidget *m_pServerIpList;
    QListWidget *m_pClientNameList;

    QTcpServer *m_pServer;

    int chater1;
    int chater2;

    QList<QTcpSocket *> m_ConnectedSocket;
    QList<int> m_ConnectedClient;

    QThreadPool *m_pThreadPool;
};

#endif // MYTECPSERVER_H
