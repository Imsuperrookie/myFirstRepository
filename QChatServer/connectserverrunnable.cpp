#include "connectserverrunnable.h"
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>

ConnectServerRunnable::ConnectServerRunnable(QObject *parent)
    : QObject(parent)
    , nClientSocket(0)
{
    setAutoDelete(true);
}

ConnectServerRunnable::~ConnectServerRunnable()
{

}

void ConnectServerRunnable::run()
{
    if(!nClientSocket)
        return;
    m_pSocket = new QTcpSocket();
    m_pSocket->setSocketDescriptor(nClientSocket);

    if(m_pSocket->waitForReadyRead())
    {
        /*
        QByteArray msg = m_pSocket->readAll();
        QString strUserAndPasswd = QVariant(msg).toString();
        qDebug() << strUserAndPasswd << msg;
        verifyUserInfo(strUserAndPasswd);
        */
        QDataStream in;
        in.setDevice(m_pSocket);
        in.startTransaction();
        QByteArray receData;
        in >> receData;

        QString str = QString(receData);

        qDebug() << "receData" << str << receData;
    }
}

bool ConnectServerRunnable::verifyUserInfo(QString userAndPasswd)
{
    qDebug() << userAndPasswd;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("QChatDB");
    db.setUserName("root");
    db.setPassword("jsd123");
    if(!db.open())
        qDebug() << "open fail";

    QSqlQuery query;
    query.exec("select...");
    QCryptographicHash md5IdAndPasswd(QCryptographicHash::Md5);

    return false;
}
