#include "mythread.hh"

#include <QDebug>

myThread::myThread(QString s, QMutex *Mutex):
    name_( s ),
    mutex_( Mutex )
{
}

void myThread::run()
{
    for( int i = 0; i < 101; ++i)
    {
        mutex_->lock();
        qDebug() << this->name_ << " " << i;
        mutex_->unlock();
    }
}
