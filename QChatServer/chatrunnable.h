#ifndef CHATRUNNABLE_H
#define CHATRUNNABLE_H

#include <QObject>
#include <QRunnable>

class ChatRunnable : public QObject, public QRunnable
{
    Q_OBJECT

public:
    ChatRunnable(QObject *parent = 0);
    ~ChatRunnable();

    void setFromClient(int descriptor);
    void setToClient(int descriptor);
    void setMsg(QString msg);

    //int getFromClient() const;
    //int getToClient() const;

protected:
    void run();

private:
    int m_nFromClient;
    int m_nToClient;
    QString m_strMsg;
};

#endif // CHATRUNNABLE_H
