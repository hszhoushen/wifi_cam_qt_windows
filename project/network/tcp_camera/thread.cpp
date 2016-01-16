#include "thread.h"
#include "tcp.h"
#include "mainwindow.h"

#include <QDebug>

Thread::Thread()
{


}

void Thread::run()
{

   tcp_get_data();
}
