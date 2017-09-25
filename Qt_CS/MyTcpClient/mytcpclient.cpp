#include "mytcpclient.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QtNetwork>
#include <QListWidget>
#include <QMessageBox>
#include <QDebug>

MyTcpClient::MyTcpClient(QWidget *parent)
    : QWidget(parent)
    , bHasSendId(false)
{
    setFixedSize(320,480);

    m_pIdLabel = new QLabel("Your ID:");
    m_pIdLineEdit = new QLineEdit();

    QHBoxLayout *pIdLayout = new QHBoxLayout();
    pIdLayout->addWidget(m_pIdLabel);
    pIdLayout->addWidget(m_pIdLineEdit);

    m_pConnectButton = new QPushButton();
    m_pConnectButton->setText(QString("Connect Server"));
    m_pConnectStatusLabel = new QLabel(QString("Click Connect Server Button"));
    m_pConnectStatusLabel->setFixedHeight(30);

    m_pFriendIdLabel = new QLabel(QString("Friend ID:"));
    m_pFriendIdLineEdit = new QLineEdit();
    QHBoxLayout *pFriendIdLayout = new QHBoxLayout();
    pFriendIdLayout->addWidget(m_pFriendIdLabel);
    pFriendIdLayout->addWidget(m_pFriendIdLineEdit);

    m_pChatContent = new QListWidget();
    m_pChatLineEdit = new QLineEdit();
    m_pSendButton = new QPushButton();
    m_pChatContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_pSendButton->setText(QString("Send"));

    QVBoxLayout *pBaseLayout = new QVBoxLayout(this);
    pBaseLayout->addLayout(pIdLayout,0);
    pBaseLayout->addWidget(m_pConnectButton, 0, Qt::AlignHCenter);
    pBaseLayout->addWidget(m_pConnectStatusLabel, 0, Qt::AlignHCenter);
    pBaseLayout->addLayout(pFriendIdLayout);
    pBaseLayout->addWidget(m_pChatContent);
    pBaseLayout->addWidget(m_pChatLineEdit,1);
    pBaseLayout->addWidget(m_pSendButton, 0, Qt::AlignRight);
    pBaseLayout->setSpacing(5);

    connect(m_pConnectButton, SIGNAL(clicked(bool)), this, SLOT(connectServer()));
}

MyTcpClient::~MyTcpClient()
{

}

void MyTcpClient::connectServer()
{
    qDebug() << "connect Server...";
    m_pSocket = new QTcpSocket(this);
    connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(receiveData()));
    m_pSocket->connectToHost("127.0.0.1", 8081);
}

void MyTcpClient::receiveData()
{
    if(m_pIdLineEdit->text().isEmpty())
    {
        QMessageBox::information(this,"Warning！","Please Enter Your ID!");
    }
    else if(m_pSocket->bytesAvailable())
    {
        QDataStream in;
        in.setDevice(m_pSocket);
        in.startTransaction();
        QString data;
        in >> data;
        qDebug() << data;
        if(!bHasSendId)
        {
            m_pConnectStatusLabel->setText(data);

            //发送ID
            QByteArray dataSend;
            QDataStream out(&dataSend, QIODevice::WriteOnly);
            out << QString(m_pIdLineEdit->text());
            m_pSocket->write(dataSend);

            connect(m_pSendButton, SIGNAL(clicked(bool)), this, SLOT(sendData()));
            bHasSendId = true;
        }
        else
        {
            m_pChatContent->addItem(data);
        }

    }
}

void MyTcpClient::sendData()
{
    if(m_pChatLineEdit->text().isEmpty())
        QMessageBox::warning(this, "Warning!", "Please Enter The Content!");
    else
    {
        QByteArray data;
        QDataStream in(&data, QIODevice::WriteOnly);
        QString strMsg;
        strMsg.append(m_pIdLineEdit->text());
        strMsg.append(m_pChatLineEdit->text());
        strMsg.append(m_pFriendIdLineEdit->text());

        in << strMsg;
        m_pSocket->write(data);
        m_pSocket->flush();
        m_pChatLineEdit->clear();
    }
}
