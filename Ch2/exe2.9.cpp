#include <iostream>

void foo()
{
#define MY_NAME "Alex"
}

int main()
{
	#ifdef MY_NAME
        std::cout << "My name is: " << MY_NAME << '\n';
    #endif
	
    return 0;
}
