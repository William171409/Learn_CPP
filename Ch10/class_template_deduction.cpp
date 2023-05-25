// define our own Pair type
template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

//Without the deduction guide(following two lines), the C++17 compiler will report the error
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

int main()
{
    Pair<int, int> p1{ 1, 2 }; // ok: we're explicitly specifying the template arguments
    Pair p2{ 1, 2 };           // compile error in C++17

    return 0;
}