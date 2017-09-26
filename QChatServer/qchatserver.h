#ifndef QCHATSERVER_H
#define QCHATSERVER_H

#include <QTcpServer>

class QThreadPool;
class QChatServer : public QTcpServer
{
    Q_OBJECT

public:
    QChatServer(QObject *parent = 0);
    ~QChatServer();
    
    void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;
    
public slots:
    void startServer(int port);
    void stopServer();
    
signals:
    void serverStarted();
    void serverStopped();
    
private:
    QThreadPool *m_pThreadPool;
};

#endif // QCHATSERVER_H
