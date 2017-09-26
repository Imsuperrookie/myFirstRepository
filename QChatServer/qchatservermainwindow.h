#ifndef QChatServerMainWindow_H
#define QChatServerMainWindow_H

#include <QWidget>

class QGroupBox;
class QLabel;
class QSpinBox;
class QPushButton;
class QChatServer;
class QChatServerMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QChatServerMainWindow(QWidget *parent = 0);
    ~QChatServerMainWindow();

private slots:
    void onStartButtonClicked();
    void onStopButtonClicked();

private:
    QGroupBox *m_pServerBox;
    QLabel *m_pIpLabelTitle;
    QLabel *m_pIpLabel;
    QLabel *m_pPortLabelTitle;
    QLabel *m_pPortLabel;
    QLabel *m_pServerStatusLabelTitle;
    QLabel *m_pServerStatusLable;
    QLabel *m_pCurrentOnLineNumberLabelTitle;
    QLabel *m_pCurrentOnLineNumberLabel;

    QLabel *m_pPortNumberLabel;
    QSpinBox *m_pPortNumber;
    QPushButton *m_pStartServerButton;
    QPushButton *m_pStopServerButton;

    QChatServer *m_pServer;
    bool m_bRunning;
};

#endif // QChatServerMainWindow_H
