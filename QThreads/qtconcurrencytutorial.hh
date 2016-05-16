#ifndef QTCONCURRENCYTUTORIAL_HH
#define QTCONCURRENCYTUTORIAL_HH

#include <QString>
#include <QDebug>
#include <QThread>

#include <QMutex>

static QMutex coutMutex;

void myRunFunction(QString name);

#endif // QTCONCURRENCYTUTORIAL_HH
