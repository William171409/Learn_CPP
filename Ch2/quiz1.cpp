#include <iostream>

int getInteger();
void print_sum(int a,int b);

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

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };
    print_sum(x,y);
	return 0;
}