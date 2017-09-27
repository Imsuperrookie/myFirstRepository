#include "qchatclientmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QChatClientMainWindow w;
    w.show();

    return a.exec();
}
