#include <iostream>

int sumDigit(int a)
{
    if (a == 0)
        return 0;
    else
        return sumDigit(a/10)+a%10;    //INteresting fact, different from other languages, C/C++ 's modulo
                                       //output a negative result!!!!!!!!!!!!!!    
}

int main()
{
    std::cout << "Sum of digit of -423: " << sumDigit(-423) <<std::endl;
    return 0;
}