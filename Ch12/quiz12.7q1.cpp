#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <array>

struct Student
{
    /* data */
    std::string_view name{};
    double score{};
};

int main()
{

    // To make sure that we reuse the lambda expression! bool (*)(const Student&,const Student&)
    // Method 1:
    auto comparison{[](const auto &a, const auto &b)
                    {
                        return a.score < b.score;
                    }};

    // Note: When using std::funciton to initialize a lambda expression, if you want to ignore the template of
    // std::funciton <>....,dont use auto deduction of the input parameters of lambda expression.

    // Method 2:
    //  Using std::function. The lambda could have a non-empty capture clause (discussed next lesson).
    //    std::function comparison{ // note: pre-C++17, use std::function<double(double, double)> instead
    //      [](const Student& a, const Student& b)
    //                 {
    //                     return a.score<b.score;
    //                 }
    //    };
    std::array<Student, 8> arr{
        {{"Albert", 8},
         {"Ben", 5},
         {"Christine", 2},
         {"Dan", 8}, // Dan has the most points (8).
         {"Enchilada", 4},
         {"Francis", 1},
         {"Greg", 3},
         {"Hagrid", 15}}};

    auto result = std::max_element(arr.begin(), arr.end(), comparison);
    // The data type of result is actually Student* a pointer to struct Student
    std::cout << result->name << " is the best student with a score of " << result->score << '\n';

    return 0;
}