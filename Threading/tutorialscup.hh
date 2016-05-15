#ifndef TUTORIALSCUP_HH
#define TUTORIALSCUP_HH

#include <iostream>
#include <thread>

void program_itself_cup();

class myFunctor
{
public:
    void publicFunction()
    {
        std::cout << "public function of myFunctor class is called" << std::endl;
    }


    void operator()()
    {
        std::cout << "This is my function object" << std::endl;
    }
};

class myFunctorParam
{
public:
    void operator()(int* arr, int length)
    {
        std::cout << "An array of length " << length << " is passed to thread" << std::endl;
        for (int i = 0; i != length; ++i)
            std::cout << arr[i] << " " << std::endl;
        std::cout << std::endl;
    }


    void changeSign(int* arr, int length)
    {
        std::cout << "An array of length " << length << " is passed to thread" << std::endl;
        for (int i = 0; i != length; ++i)
            std::cout << arr[i] << " ";
        std::cout << "Changing sign of all elements of initial array" << std::endl;
        for (int i = 0; i != length; ++i)
        {
            arr[i] *= -1;
            std::cout << arr[i] << " ";
        }
    }
};

#endif // TUTORIALSCUP_HH
