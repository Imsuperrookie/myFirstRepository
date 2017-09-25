#ifndef MYTCPCLIENT_H
#define MYTCPCLIENT_H

#include <QWidget>

class QPushButton;
class QLineEdit;
class QLabel;
class QTcpSocket;
class QListWidget;
class MyTcpClient : public QWidget
{
    Q_OBJECT

public:
    MyTcpClient(QWidget *parent = 0);
    ~MyTcpClient();

private slots:
    void connectServer();
    void receiveData();
    void sendData();

private:
    QLabel *m_pIdLabel;
    QLineEdit *m_pIdLineEdit;
    QPushButton *m_pConnectButton;
    QLabel *m_pConnectStatusLabel;
    QLabel *m_pFriendIdLabel;
    QLineEdit *m_pFriendIdLineEdit;
    QLineEdit *m_pChatLineEdit;
    QPushButton *m_pSendButton;
    QListWidget *m_pChatContent;

    QTcpSocket *m_pSocket;

    bool bHasSendId;
};

#endif // MYTCPCLIENT_H
