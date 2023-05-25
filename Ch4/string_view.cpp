#include <iostream>
#include <string_view>

int main()
{
    constexpr std::string_view s{ "Hello, world!" };
    std::cout << s << '\n'; // s will be replaced with "Hello, world!" at compile-time

    return 0;
}