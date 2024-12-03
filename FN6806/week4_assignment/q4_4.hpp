#pragma once
#include <memory>
using namespace std;
struct A
{
    shared_ptr<int> x;
    // we shall use make_shared below. but make_unique also compiles.
    // Here is the reason.
    // By using make_unique to create a unique_ptr<int> and then initializing a
    // shared_ptr<int> with it, you transfer ownership of the dynamically
    // allocated int from the unique_ptr to the shared_ptr.
    A() : x(make_unique<int>(1)) {}

    A(const A& other) : x(make_shared<int>(*other.x)) {}

    A& operator=(const A& other)
    {
        if (this != &other)
        {
            x = make_shared<int>(*other.x); 
        }
        return *this;
    }

};
struct B
{
    unique_ptr<int> x;
    B() : x(make_unique<int>(1)) {}
    B(const B& other) : x(make_unique<int>(*other.x)) {}

    B& operator=(const B& other) {
        if (this != &other) {
            x = make_unique<int>(*other.x);
        }
        return *this;
    }

};


void q4_4(void);