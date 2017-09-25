#include "qchatservermainwindow.h"
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include <QSpinBox>
#include <QLayout>

QChatServerMainWindow::QChatServerMainWindow(QWidget *parent) :
    QWidget(parent),
    m_pIpLabelTitle(new QLabel(QString("Server IP:"))),
    m_pIpLabel(new QLabel(QString("127.0.0.1"))),
    m_pPortLabelTitle(new QLabel(QString("Port:"))),
    m_pPortLabel(new QLabel(QString("8888"))),
    m_pServerStatusLabelTitle(new QLabel(QString("Server Status:"))),
    m_pServerStatusLable(new QLabel(QString("Running..."))),
    m_pServerBox(new QGroupBox(this)),
    m_pCurrentOnLineNumberLabelTitle(new QLabel(QString("Online Number:"))),
    m_pCurrentOnLineNumberLabel(new QLabel(QString("0"))),
    m_pPortNumber(new QSpinBox),
    m_pPortNumberLabel(new QLabel("Port Number:")),
    m_pStartServerButton(new QPushButton(QString("Start Server"))),
    m_pStopServerButton(new QPushButton(QString("Stop Server"))),
    m_bRunning(true)
{
    setFixedSize(350,140);
    setWindowTitle(QString("服务器控制台"));
    m_pServerBox->setTitle(QString("服务器信息"));

    m_pPortNumber->setMaximum(10000);
    m_pPortNumber->setValue(8888);
    m_pStartServerButton->setFixedSize(100,30);
    m_pStopServerButton->setFixedSize(100,30);
    m_pServerStatusLable->setFixedWidth(50);
    m_pIpLabelTitle->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_pPortLabelTitle->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_pServerStatusLabelTitle->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_pCurrentOnLineNumberLabelTitle->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QString strStyleSheet = "QLabel {font-family: MicroSoft Yahei}";
    m_pIpLabelTitle->setStyleSheet(strStyleSheet);
    m_pIpLabel->setStyleSheet("QLabel {color: blue; font: bold; font-style: italic;}");
    m_pPortLabelTitle->setStyleSheet(strStyleSheet);
    m_pPortLabel->setStyleSheet("QLabel {color: #8B3A62; font: bold}");
    m_pServerStatusLabelTitle->setStyleSheet(strStyleSheet);
    m_pServerStatusLable->setStyleSheet("QLabel {color: green; font: bold}");
    m_pCurrentOnLineNumberLabelTitle->setStyleSheet(strStyleSheet);
    m_pCurrentOnLineNumberLabel->setStyleSheet("QLabel {color: #6495ED; font: bold}");

    QHBoxLayout *pIpLayout = new QHBoxLayout();
    pIpLayout->addWidget(m_pIpLabelTitle);
    pIpLayout->addWidget(m_pIpLabel);
    pIpLayout->setSpacing(10);

    QHBoxLayout *pPortLayout = new QHBoxLayout();
    pPortLayout->addWidget(m_pPortLabelTitle);
    pPortLayout->addWidget(m_pPortLabel);
    pPortLayout->setSpacing(10);

    QHBoxLayout *pServerStatusLayout = new QHBoxLayout();
    pServerStatusLayout->addWidget(m_pServerStatusLabelTitle);
    pServerStatusLayout->addWidget(m_pServerStatusLable, 0, Qt::AlignLeft);
    pServerStatusLayout->setSpacing(10);

    QHBoxLayout *pOnlineNumberLayout = new QHBoxLayout();
    pOnlineNumberLayout->addWidget(m_pCurrentOnLineNumberLabelTitle);
    pOnlineNumberLayout->addWidget(m_pCurrentOnLineNumberLabel);
    pOnlineNumberLayout->setSpacing(10);

    QVBoxLayout *pBoxLayout = new QVBoxLayout(m_pServerBox);
    pBoxLayout->addLayout(pIpLayout);
    pBoxLayout->addLayout(pPortLayout);
    pBoxLayout->addLayout(pServerStatusLayout);
    pBoxLayout->addLayout(pOnlineNumberLayout);

    QHBoxLayout *pPortNumberLayout = new QHBoxLayout();
    pPortNumberLayout->addWidget(m_pPortNumberLabel);
    pPortNumberLayout->addWidget(m_pPortNumber);
    pPortNumberLayout->setSpacing(10);

    QVBoxLayout *pStartServerLayout = new QVBoxLayout();
    pStartServerLayout->addSpacing(20);
    pStartServerLayout->addLayout(pPortNumberLayout, 1);
    pStartServerLayout->addStretch();
    pStartServerLayout->addWidget(m_pStartServerButton, 0, Qt::AlignCenter);
    pStartServerLayout->addWidget(m_pStopServerButton, 0, Qt::AlignCenter);
    pStartServerLayout->addSpacing(20);

    QHBoxLayout *pBaseLayout = new QHBoxLayout(this);
    pBaseLayout->addWidget(m_pServerBox);
    pBaseLayout->addLayout(pStartServerLayout);

    connect(m_pPortNumber, SIGNAL(valueChanged(QString)), m_pPortLabel, SLOT(setText(QString)));
    connect(m_pStartServerButton, SIGNAL(clicked(bool)), this, SLOT(onStartButtonClicked()));
    connect(m_pStopServerButton, SIGNAL(clicked(bool)), this, SLOT(onStopButtonClicked()));
}

QChatServerMainWindow::~QChatServerMainWindow()
{
}

void QChatServerMainWindow::onStartButtonClicked()
{
    if(!m_bRunning)
    {
        m_bRunning = true;
        m_pServerStatusLable->setText(QString("Running"));
        m_pServerStatusLable->setStyleSheet("QLabel {color: green; font: bold}");
    }
}

void QChatServerMainWindow::onStopButtonClicked()
{
    if(m_bRunning)
    {
        m_bRunning = false;
        m_pServerStatusLable->setText(QString("Stopped"));
        m_pServerStatusLable->setStyleSheet("QLabel {color: red; font: bold}");
    }
}
