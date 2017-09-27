#ifndef CONNECTSERVERRUNNABLE_H
#define CONNECTSERVERRUNNABLE_H

#include <QObject>
#include <QRunnable>

class QTcpSocket;
class ConnectServerRunnable : public QObject, public QRunnable
{
    Q_OBJECT

public:
    ConnectServerRunnable(QObject *parent);
    ~ConnectServerRunnable();

    int nClientSocket;

protected:
    void run();

private:
    bool verifyUserInfo(QString userAndPasswd);

private:
    QTcpSocket *m_pSocket;
};

#endif // CONNECTSERVERRUNNABLE_H
