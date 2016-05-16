#ifndef MYTHREAD_HH
#define MYTHREAD_HH

#include <QThread>
#include <QString>

class myThread : public QThread
{
public:
    explicit myThread( QString s );

    void run();
private:
    QString name_;
};

#endif // MYTHREAD_HH
