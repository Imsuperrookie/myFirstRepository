#ifndef LOGINSERVERRUNNABLE_H
#define LOGINSERVERRUNNABLE_H

#include <QObject>
#include <QRunnable>

class QTcpSocket;
class LoginServerRunnable : public QObject, public QRunnable
{
    Q_OBJECT

public:
    LoginServerRunnable(QObject *parent);
    ~LoginServerRunnable();

    int nClientSocket;

protected:
    void run();

private:
    bool verifyUserInfo(QString userAndPasswd);

private:
    QTcpSocket *m_pSocket;
};

#endif // LOGINSERVERRUNNABLE_H
