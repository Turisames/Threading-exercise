#include "mythread.hh"
#include "qtconcurrencytutorial.hh"

#include <iostream>

#include <QCoreApplication>
#include <qtconcurrentrun.h>
#include <QThread>

#ifndef QT_NO_CONCURRENT

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ///    QThread tutorial
    /*myThread thread1("A"), thread2("B"), thread3("C");

    thread1.start();
    thread2.start();
    thread3.start();*/

    ///     QtConcurrent tutorial
    QFuture<void> t1 = QtConcurrent::run( myRunFunction, QString("A") );
    QFuture<void> t2 = QtConcurrent::run( myRunFunction, QString("B") );
    QFuture<void> t3 = QtConcurrent::run( myRunFunction, QString("C") );

    t1.waitForFinished();
    t2.waitForFinished();
    t3.waitForFinished();

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
