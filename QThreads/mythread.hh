#ifndef MYTHREAD_HH
#define MYTHREAD_HH

#include <QThread>
#include <QMutex>
#include <QString>

//static QMutex * mutex = new QMutex;

class myThread : public QThread
{
public:
    explicit myThread( QString s, QMutex * Mutex );

    void run();
private:
    QString name_;
    QMutex * mutex_;
};

#endif // MYTHREAD_HH
