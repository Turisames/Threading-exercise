#include "tutorialscup.hh"

#include <thread>
#include <iostream>


void
threadFunction()
{
    std::cout << " This is a thread \n";
}
void
joinableTest()
{
    std::thread funcTest1( threadFunction );

    funcTest1.detach();
    if( funcTest1.joinable() )
    {
        funcTest1.join();
    }else
    {
        std::cout << "The thread had been detached." << std::endl;
    }
}

void
functorfunc()
{
    myFunctor myFunc;
    std::thread functorTest( &myFunctor::publicFunction , myFunc );
    if ( functorTest.joinable() )
        functorTest.join();
}

void
printSomeValues(int val, char* str, double dval)
{
    std::cout << val << " " << str <<" " << dval << std::endl;

}

void
params_into_threads()
{
    char* str = "Hello";
    //5, str and 3.2 are passed to printSomeValues function
    std::thread paramPass(printSomeValues, 5, str, 3.2);
    if (paramPass.joinable())
    paramPass.join();
}

void
params_class_into_thread()
{
    //these parameters will be passed to thread
    int arr[5] = { 1, 3, 5, 7, 9 };
    myFunctorParam objParamPass;
    std::thread test(objParamPass, arr, 5);
    if (test.joinable())
        test.join();
}

void
params_class_into_thread_other()
{
    int arr2[5] = { -1, 3, 5, -7, 0 };
    myFunctorParam objParamPass;
    //initialize thread with member function
    std::thread test2(&myFunctorParam::changeSign, &objParamPass, arr2, 5);
    if (test2.joinable())
        test2.join();
}

// This function is invoked in the main.
void
program_itself_cup()
{

    //functorfunc();
    //params_into_threads();
    //params_class_into_thread();
    params_class_into_thread_other();
}
