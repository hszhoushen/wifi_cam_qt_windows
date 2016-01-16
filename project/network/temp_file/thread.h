#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QDebug>

class Thread  : public QThread
{
  Q_OBJECT
public:
    Thread();
    QThread *workThread[2];
    void stop();
protected:
    void run();
};

//add
class Worker : public QObject
{
    Q_OBJECT
private slots:
    void onTimeout()
    {
        qDebug()<<"Worker::onTimeout get called from?: "<<QThread::currentThreadId();
    }

};

#endif // THREAD_H
