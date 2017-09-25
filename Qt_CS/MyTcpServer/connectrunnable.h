#ifndef CONNECTRUNNABLE_H
#define CONNECTRUNNABLE_H

#include<QRunnable>
#include <QObject>

class QTcpSocket;
class ConnectRunnable : public QObject, public QRunnable
{
    Q_OBJECT

public:
    ConnectRunnable(QObject *parent = 0);
    ~ConnectRunnable();

    int nSocketDescriptor;

protected:
    void run();

signals:
    void finished(int descriptor, QString id);

private:
    QTcpSocket *m_pSocket;
};

#endif // CONNECTRUNNABLE_H
