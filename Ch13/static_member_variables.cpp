#include <iostream>

class Something
{
private:
    static inline int s_idGenerator { 1 }; // C++17
//  static int s_idGenerator;              // Use this instead for C++14 or older
    int m_id { };

public:
    Something()
    : m_id { s_idGenerator++ } // grab the next value from the id generator
    {}

    int getID() const { return m_id; }
};

// For C++14 or older, we have to initialize the non-const static member outside the class definition
// Note that we're defining and initializing s_idGenerator even though it is declared as private above.
// This is okay since the definition isn't subject to access controls.
// int Something::s_idGenerator { 1 }; // start our ID generator with value 1 (uncomment for C++14 or older)

int main()
{
    Something first;
    Something second;
    Something third;

    std::cout << first.getID() << '\n';
    std::cout << second.getID() << '\n';
    std::cout << third.getID() << '\n';
    return 0;
}