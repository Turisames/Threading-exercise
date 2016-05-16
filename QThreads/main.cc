#include "mythread.hh"
#include "qtconcurrencytutorial.hh"

#include <iostream>

#include <QCoreApplication>
#include <qtconcurrentrun.h>
#include <QThread>
#include <QFutureSynchronizer>

#ifndef QT_NO_CONCURRENT

void qthread_tutorial()
{
    QMutex mutex;
    myThread thread1("A", &mutex), thread2("B", &mutex), thread3("C", &mutex);

    thread1.start();
    thread2.start();
    thread3.start();

    thread1.wait();
    thread2.wait();
    thread3.wait();
}

void qtconcurrent_run_tutorial()
{
    QFutureSynchronizer<void> syncr;

    //coutMutex = QMutex();

    QFuture<void> t1 = QtConcurrent::run( myRunFunction,
                                          QString("A") );
    syncr.addFuture( t1 );
    QFuture<void> t2 = QtConcurrent::run( myRunFunction,
                                          QString("B") );
    syncr.addFuture( t2 );
    QFuture<void> t3 = QtConcurrent::run( myRunFunction,
                                          QString("C") );
    syncr.addFuture( t3 );

    /*
    t1.waitForFinished();
    t2.waitForFinished();
    t3.waitForFinished();
    */
    syncr.waitForFinished();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ///    QThread tutorial
    //qthread_tutorial();

    ///     QtConcurrent tutorial
    qtconcurrent_run_tutorial();

    //std::exit( 0 );
    return a.exec();
}

#else

#include <QLabel>

int main( int argc, char* argv[] )
{
    QApplication app(argc, argv);

    QString text{ "QTConcurrent is not currently supported on this platform." };

    QLabel * label = new QLabel(text);
    label->setWordWrap( true );

    label->show();
    app.exec();
}
#endif
