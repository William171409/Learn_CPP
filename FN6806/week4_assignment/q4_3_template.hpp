#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

template <class T> class Stack {
    int _top; // index of the top element;
    // if stack is empty, top is set to -1
    int max_size; // maximum number of elements of stack
    vector<T> items; // contains items in the stack
public:
    Stack():_top{-1}{}
    Stack(int size):_top{-1},max_size{size}{
        items.resize(size);
    } 
    // set top to c-1 (since there are no elements yet);
    // set max_size to size;
    // reserve memory for size elements in items

    inline void push(T item)
    {
        // if (_top + 1 >= max_size) {
        //     throw overflow_error("Stack overflow.");
        // }
        // items[++_top] = item;
        if (++_top >= static_cast<int>(items.size())) {
            items.push_back(item); 
        } else {
            items[_top] = item;
        }
        // In DFS_A, it might not be clear (at least I do not know) the max_size of the stack. Hence, I decided to
        // implement method push in such a way

    } 
    // increase top by 1 and set items[top]=item;
    // exit with error message if number of items
    // becomes larger than max_size
    inline void pop()
    {
        if (_top >= 0) {
            --_top;
        } else {
            cerr << "Can't pop from an empty stack.\n";
        }

    }
    // decrease top by 1 if top>=0; do nothing otherwise
    // note that the top element is actually NOT
    // removed from the array items (there is not need to)
    inline T top()
    {
        if (_top >= 0) {
            return items[_top];
        } else {
            throw underflow_error("Stack is empty.");
        }
    } 
    // return the top element;
    // exit with error message if stack iex_2.4_matrix_unique_ptrs empty
    inline int size()
    {
        return _top+1;
    } // return number of items in stack
    inline bool is_empty()
    {
        return _top==-1;
    } // return true if and only if stack is empty
};