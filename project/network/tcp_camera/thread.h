#ifndef THREAD_H
#define THREAD_H

#include <QThread>


class Thread  : public QThread
{
  Q_OBJECT
public:
    Thread();
//    QThread *workThread[2];
    void stop();
protected:
    void run();
};

#endif // THREAD_H
