#include <QCoreApplication>
#include "cuser.h"
#include "cmonitor.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CUser h("xyz");
    h.load();
    h.save();
    CMonitor::getInstance()->showmsg(h.account);
    return a.exec();
}
