#ifndef CHATRUNNABLE_H
#define CHATRUNNABLE_H

#include <QObject>
#include <QRunnable>

class QTcpSocket;
class ChatRunnable : public QObject, public QRunnable
{
    Q_OBJECT

public:
    ChatRunnable(QObject *parent = 0);
    ~ChatRunnable();

    int nToClientSocketDescriptor;
    QString strMsg;

    void run() Q_DECL_OVERRIDE;

private:
    QTcpSocket *m_pSocket;
};

#endif // CHATRUNNABLE_H
