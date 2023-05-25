#include <iostream>
#include "quiz3.h"


void print_sum(int a,int b)
{
    std::cout<<"The sum of "<<a<<" and "<<b<<" is "<<a+b<<std::endl;
}

int getInteger()
{   
    int a{};
    std::cout<<"Enter an integer: ";
    std::cin >> a;
    return a;
}