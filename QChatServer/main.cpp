#include "qchatservermainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QChatServerMainWindow w;
    w.show();

    return a.exec();
}
