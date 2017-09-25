#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QWidget>

class QListWidget;
class MyServer;
class MyTcpServer : public QWidget
{
    Q_OBJECT

public:
    MyTcpServer(QWidget *parent = 0);
    ~MyTcpServer();

private:
    QListWidget *m_pConnectedClient;
    MyServer *m_pServer;
};

#endif // MYTCPSERVER_H
