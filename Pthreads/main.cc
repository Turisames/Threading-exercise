//#include "fromtutorialspoint.hh"

#include <iostream>
#include <pthread.h>
#include <QCoreApplication>

static pthread_mutex_t GLOBAL_MUTEX = PTHREAD_MUTEX_INITIALIZER;
static long universal;

void * myOwnThreadFunction( void* )
{
    for (int i = 0; i < 101; ++i)
    {
        pthread_mutex_lock( &GLOBAL_MUTEX );
        universal++;
        std::cout << "Thread 1: The value of universal is " << universal << std::endl;
        pthread_mutex_unlock( &GLOBAL_MUTEX );
    }

    pthread_exit( NULL );
}

void * mySecondThreadFunction( void * )
{
    for (int i = 0; i < 101; ++i)
    {
        pthread_mutex_lock( &GLOBAL_MUTEX );
        universal--;
        std::cout << "Thread 2: The value of universal is " << universal << std::endl;
        pthread_mutex_unlock( &GLOBAL_MUTEX );
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
    //int param{ 100 };//(void*) &param

    pthread_create( &thread1, NULL, myOwnThreadFunction, NULL);
    pthread_create( &thread2, NULL, mySecondThreadFunction, NULL );

    std::cout << "\tmain(): Done creating threads." << std::endl;
    pthread_join( thread1, NULL );
    std::cout << "\tmain(): thread1 is ready." << std::endl;
    pthread_join( thread2, NULL );

    std::cout << "\tmain(): Printing is ready." << std::endl;
    pthread_exit( NULL );

    return a.exec();
}
