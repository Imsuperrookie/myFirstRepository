#ifndef QCHATCLIENTMAINWINDOW_H
#define QCHATCLIENTMAINWINDOW_H

#include <QWidget>

namespace Ui {
class QChatClientMainWindow;
}

class QPushButton;
class QLabel;
class QLineEdit;
class QTcpSocket;
class QChatClientMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QChatClientMainWindow(QWidget *parent = 0);
    ~QChatClientMainWindow();

private slots:
    void createRegisterWidget();

private:

private:
    Ui::QChatClientMainWindow *ui;

    QLineEdit *m_pIdLineEdit;
    QLineEdit *m_pPasswdLineEdit;

    QPushButton *m_pLoginButton;
    QPushButton *m_pRegisterButton;

    QTcpSocket *m_pSocket;
};

#endif // QCHATCLIENTMAINWINDOW_H
