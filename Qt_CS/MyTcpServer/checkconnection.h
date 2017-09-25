#ifndef CHECKCONNECTION_H
#define CHECKCONNECTION_H

#include <QObject>
#include <QRunnable>

class CheckConnection : public QObject, public QRunnable
{
    Q_OBJECT

public:
    CheckConnection(QObject *parent = 0);
    ~CheckConnection();

    void run() Q_DECL_OVERRIDE;
};

#endif // CHECKCONNECTION_H
