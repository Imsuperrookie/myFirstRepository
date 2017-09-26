#include "chatrunnable.h"

ChatRunnable::ChatRunnable(QObject *parent)
    : QObject(parent)
    , m_nFromClient(0)
    , m_nToClient(0)
{

}

ChatRunnable::~ChatRunnable()
{

}

void ChatRunnable::setFromClient(int descriptor)
{
    m_nFromClient = descriptor;
}

void ChatRunnable::setToClient(int descriptor)
{
    m_nToClient = descriptor;
}

void ChatRunnable::setMsg(QString msg)
{
    m_strMsg = msg;
}

/*int ChatRunnable::getFromClient() const
{
    return m_nFromClient;
}

int ChatRunnable::getToClient() const
{
    return m_nToClient;
}
*/
void ChatRunnable::run()
{
    if(!m_nFromClient || m_nToClient)
        return;

    //检测是否有敏感词汇

    //处理敏感词汇

    //发送到 ToClient
}
