#include "qchatclientmainwindow.h"
#include "ui_qchatclientmainwindow.h"
#include <QLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QEventLoop>
#include <QDialog>
#include <QtNetwork>
#include <QMessageBox>
#include <QDebug>

QChatClientMainWindow::QChatClientMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QChatClientMainWindow),
    m_pIdLineEdit(new QLineEdit),
    m_pPasswdLineEdit(new QLineEdit),
    m_pLoginButton(new QPushButton("登录")),
    m_pRegisterButton(new QPushButton("注册")),
    m_pSocket(new QTcpSocket(this))
{
    ui->setupUi(this);
    setFixedSize(320,240);
    setWindowTitle(QString("QChat 客户端"));

    QFormLayout *pFormLayout = new QFormLayout();
    pFormLayout->addRow(QStringLiteral("账号："), m_pIdLineEdit);
    pFormLayout->addRow(QStringLiteral("密码："),m_pPasswdLineEdit);

    QHBoxLayout *pBtnLayout = new QHBoxLayout();
    pBtnLayout->addWidget(m_pLoginButton);
    pBtnLayout->addWidget(m_pRegisterButton);

    QVBoxLayout *pBaseLayout = new QVBoxLayout(this);
    pBaseLayout->addLayout(pFormLayout);
    pBaseLayout->addLayout(pBtnLayout);
    pBaseLayout->setMargin(40);
    pBaseLayout->setSpacing(20);

    connect(m_pRegisterButton, SIGNAL(clicked(bool)), this, SLOT(createRegisterWidget()));


}

QChatClientMainWindow::~QChatClientMainWindow()
{
    delete ui;
}

void QChatClientMainWindow::createRegisterWidget()
{
    QEventLoop eventLoop;

    qDebug() << "create dialog";
    QDialog registerDlg(this);
    registerDlg.setModal(true);

    QLineEdit nickName;
    QPushButton registerBtn(QStringLiteral("注册"));
    QLabel registerStatusLabel;
    QLabel registerInfo;

    registerBtn.setFixedWidth(registerDlg.width()*0.4);

    QFormLayout nickeLayout;
    nickeLayout.addRow(QStringLiteral("昵称："),&nickName);

    QVBoxLayout baseLayout(&registerDlg);
    baseLayout.addLayout(&nickeLayout);
    baseLayout.addWidget(&registerBtn, 0, Qt::AlignHCenter);
    baseLayout.addWidget(&registerStatusLabel);
    baseLayout.addWidget(&registerInfo);

    QTcpSocket *pSocket = m_pSocket;
    connect(&registerBtn, &QPushButton::clicked, [&](){
        pSocket->connectToHost("127.0.0.1",8888);
        if(nickName.text().isEmpty())
            QMessageBox::warning(this,"警告！","请输入昵称...");
        else if(!pSocket->waitForConnected())
            QMessageBox::warning(this,"警告!","连接服务器失败...");
        else
        {
            QByteArray registerData;
            QDataStream out(&registerData, QIODevice::WriteOnly);

            out << QString("register guo peng fei");
            //out << nickName.text();
            out << "guo peng fei";

            pSocket->write(registerData);
        }
    });

    registerDlg.show();

    eventLoop.exec();
}
