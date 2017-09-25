#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QWidget>

class QListWidget;
class MyTcpServer : public QWidget
{
    Q_OBJECT

public:
    MyTcpServer(QWidget *parent = 0);
    ~MyTcpServer();

private:
    QListWidget *m_pConnectedClient;
};

#endif // MYTCPSERVER_H
