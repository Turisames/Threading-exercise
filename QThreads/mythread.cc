#include "mythread.hh"

#include <QDebug>

myThread::myThread(QString s):
    name_(s)
{
}

void myThread::run()
{
    for( int i = 0; i < 101; ++i)
    {
        qDebug() << this->name_ << " " << i;
    }
}
