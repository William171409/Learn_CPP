#pragma once
#include <vector>
#include <list>
template <class T1, class T2> class Pair {
    T1 _left;
    T2 _right;
public:
    Pair(const T1 &a, const T2 &b):_left{a},_right{b}{}
    inline Pair &operator=(const Pair &rhs) {
        _left = rhs.left();
        _right = rhs.right();
        return *this;
    }
    inline bool operator==(const Pair &rhs) const;

    inline T1 left() const{
        return _left;
    }
    inline T2 right() const
    {
        return _right;
    }
    inline void left(T1 a)
    {
        _left = a;
    }
    inline void right(T2 b)
    {
        _right = b;
    }

};

template <class T1, class T2> bool Pair<T1,T2>::operator==(const Pair<T1,T2>& rhs) const
{
    return (rhs.left()==_left)&&(rhs.right()==_right);
}