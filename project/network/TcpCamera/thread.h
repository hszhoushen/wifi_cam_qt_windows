#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include "tcp.h"

class Thread : public QThread
{
    Q_OBJECT

public:
    Thread();
    Thread(int port, char * ip);
    ~Thread();
public:
    void stop();
    int tcpGetData();
    void disconnect_tcp();
protected:
    void run();
signals:
    void dataUpdated(QByteArray aa);
private:
    Tcp *tcp;
};

#endif // THREAD_H
