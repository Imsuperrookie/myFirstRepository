#ifndef QCHATSERVER_H
#define QCHATSERVER_H

#include <QTcpServer>

class QChatServer : public QTcpServer
{
public:
    QChatServer(QObject *parent = 0);
    ~QChatServer();
};

#endif // QCHATSERVER_H
