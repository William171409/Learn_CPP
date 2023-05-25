#include <iostream>

class Foo
{
private:
    int m_a{ 5 };
    int m_b{ 6 };


public:
    Foo()=default;
    Foo(int a, int b)
        : m_a{ a }, m_b{ b }
    {
    }

    void print()
    {
        std::cout << m_a << ' ' << m_b << '\n';
    }

    void reset()
    {
        // consider this a bit of magic for now
        *this = Foo{}; // create new Foo object, then use assignment to overwrite our implicit object
    }
};

int main()
{
    Foo a{1,6};
    a.print();
    a.reset();
    a.print();

    return 0;
}