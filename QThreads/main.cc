#include "mythread.hh"


#include <iostream>
#include <QCoreApplication>


void
helloWorld()
{
    std::cout << "Hello, girls!" << std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    myThread thread1("A"), thread2("B"), thread3("C");

    thread1.start();
    thread2.start();
    thread3.start();

    return a.exec();
}
