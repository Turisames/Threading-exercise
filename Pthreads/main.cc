//#include "fromtutorialspoint.hh"

#include <iostream>
#include <pthread.h>
#include <QCoreApplication>

static long universal;

void * myOwnThreadFunction( void* Param )
{
    for (int i = 0; i < 101; ++i)
    {
        universal++;
        std::cout << "Thread 1: The value of universal is " << universal << std::endl;
    }

    pthread_exit( NULL );
}

void * mySecondThreadFunction( void * Param  )
{
    for (int i = 0; i < 101; ++i)
    {
        universal--;
        std::cout << "Thread 2: The value of universal is " << universal << std::endl;
    }

    pthread_exit( NULL );
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //firstPart();
    //secondPart();
    //thirdPart();

    universal = 0;
    pthread_t thread1, thread2;
    int param{ 100 };//(void*) &param

    pthread_create( &thread1, NULL,
                    myOwnThreadFunction,
                    (void*) &param );
    pthread_create( &thread2, NULL, mySecondThreadFunction, (void*) &param);

    pthread_join( thread1, NULL );
    pthread_join( thread2, NULL );

    return a.exec();
}
