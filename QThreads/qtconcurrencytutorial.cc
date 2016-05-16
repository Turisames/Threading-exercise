#include "qtconcurrencytutorial.hh"

#include <QString>
#include <QDebug>
#include <QThread>

#include <QMutex>



void myRunFunction( QString name )
{
    for(int i = 0; i <= 5; i++)
    {
        coutMutex.lock();
        qDebug() << name << " " << i <<
                    "from" << QThread::currentThread();
        coutMutex.unlock();
    }
}
