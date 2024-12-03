#include "q4_4.hpp"
#include <iostream>
#include <cassert>
void q4_4()
{

    {
        cout << "Test shared_ptr in class: " << "\n";
        A a;
        cout << *a.x << "\n";
        A b = a;
        *b.x = 3;
        cout << *b.x << ", " << *a.x << "\n";
        assert(b.x.use_count() < 2);
        A c;
        b = c;
        a = b;
        cout << *b.x << ", " << *a.x << ", " << *c.x << "\n";
        assert(b.x.use_count() < 3);
    }

    /*
        The test code of shared_ptr in class could be compiled but it will fail the assertion.
        If  user-defined copy constructor and copy assignment operator are not defined, a,b,c's data members x will
        be the co-owners of a shared_pointer and will point to the same memory address. To pass the assertion,
        user-defined copy ctor and copy assignment operator are needed.
    */

    cout << boolalpha;
    cout << "Test unique_ptr in class: " << "\n";
    B b;
    cout << *b.x << "\n";
    *b.x += 1;
    B c = b;
    cout << *c.x << "\n";
    assert(b.x != nullptr);
    cout << *b.x << "\n";
    *c.x += 1;
    b = c;
    cout << *b.x << "\n";
    assert(c.x != nullptr);
    cout << *c.x << "\n";

    /*
        The test code of unique_ptr in class could not be compiled as its copy ctor and copy assignment operator are implicilty deleted.
        Thus,deep copy constructor and deep copy assignment operator are defined.
    */


}
