#include "thread.h"
#include "tcp.h"
#include <QDebug>

Thread::Thread()
{


}

void Thread::run()
{
    //tcp初始化
    tcp_init();
}
