#include "fromtutorialspoint.hh"

#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>

#define NUM_THREADS 5

struct thread_data{
    int thread_id;
    char * message;
};

void * someFunction( void *threadID )
{
    long id{ long(threadID) };
    std::cout << "someFunction(): This is thread " << id << std::endl;

    pthread_exit( NULL );
}

void * print_message( void * threadArg )
{
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadArg;

    std::cout << "This is thread number " << my_data->thread_id << std::endl;
    std::cout << "It wants to say: " << my_data->message << std::endl;

    pthread_exit( NULL );
}

void *wait(void *t)
{
   int i;
   long tid;

   tid = (long)t;

   sleep(1);
   std::cout << "Sleeping in thread " << std::endl;
   std::cout << "Thread with id : " << tid << "  ...exiting " << std::endl;
   pthread_exit(NULL);
}

void firstPart()
{
    pthread_t threads[ NUM_THREADS ];
    int rc;

    for(int i = 0; i < NUM_THREADS; ++i )
    {
        std::cout << "main(): Creating thread number " << i << std::endl;

        rc = pthread_create( &threads[i], NULL, someFunction, (void*)i );

        if (rc)
        {
            std::cout << "There has been some error." << std::endl;
            std::exit(-1);
        }
    }
    pthread_exit( NULL );
}

void secondPart()
{
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc;

   for(int i = 0; i < NUM_THREADS; ++i)
   {
       std::cout << "main(): Creating thread " << i << std::endl;
       td[i].thread_id = i;
       td[i].message = "hi";

       rc = pthread_create( &threads[i], NULL, print_message, (void*)&td[i] );

       if (rc)
       {
           std::cout << "There was some error." << std::endl;
           exit( -1 );
       }
   }
   pthread_exit( NULL );
}

void thirdPart()
{
    int rc;
    int i;
    pthread_t threads[ NUM_THREADS ];
    pthread_attr_t attr;
    void *status;

    // Initialize and set thread joinable
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for( i=0; i < NUM_THREADS; i++ ){
      std::cout << "main() : creating thread, " << i << std::endl;
      rc = pthread_create(&threads[i], NULL, wait, (void *)i );

      if (rc){
         std::cout << "Error:unable to create thread," << rc << std::endl;
         exit(-1);
      }
    }

    // free attribute and wait for the other threads
    pthread_attr_destroy( &attr );
    for( i=0; i < NUM_THREADS; i++ ){
      rc = pthread_join(threads[i], &status);
      if (rc){
         std::cout << "Error:unable to join," << rc << std::endl;
         exit(-1);
      }
      std::cout << "Main: Completed thread id :" << i ;
      std::cout << ",  now exiting with status :" << status << std::endl;
    }

    std::cout << "Main: program exiting." << std::endl;
    pthread_exit(NULL);
}
