#include <iostream>
template <typename T>
void swapInt(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
void swapInt(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main()
{
    int a{1};
    int b{};
    std::cout << a << ' ' << b << '\n';
    swapInt(a, b);
    std::cout << a << ' ' << b << '\n';
    swapInt(&a, &b);
    std::cout << a << ' ' << b << '\n';
    return 0;
}