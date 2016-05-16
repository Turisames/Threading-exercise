#include "qtconcurrencytutorial.hh"

#include <QString>
#include <QDebug>
#include <QThread>

void myRunFunction( QString name )
{
    for(int i = 0; i <= 5; i++)
    {
        qDebug() << name << " " << i <<
                    "from" << QThread::currentThread();
    }
}
