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



    return a.exec();
}
