#include <iostream>

struct Foo
{
    int a{ };
    int b{ };
    int c{ };
};

int main()
{
    Foo f1{ .a{ 1 }, .c{ 3 } }; // ok: f1.a = 1, f1.b = 0 (value initialized), f1.c = 3
    Foo f2{ .a = 1, .c = 3 };   // ok: f2.a = 1, f2.b = 0 (value initialized), f2.c = 3
    std::cout<<"f1: "<<"a = "<<f1.a<<" "<<"b = "<<f1.b<<" "<<"c = "<<f1.c<<'\n';
    std::cout<<"f2: "<<"a = "<<f2.a<<" "<<"b = "<<f2.b<<" "<<"c = "<<f2.c<<'\n';
    return 0;
}