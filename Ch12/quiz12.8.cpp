#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <cmath>

int getInt()
{
    int a{};
    std::cin >> a;
    return a;
}

int findClosestNumber(const std::vector<int> &numbers, int guess)
{
    return *std::min_element(numbers.begin(), numbers.end(), [=](const int a, const int b)
                             { return (std::abs(a - guess) < std::abs(b - guess)); });
}

int main()
{
    std::vector<int> numList{};
    std::cout << "Start where? ";
    int start{getInt()};
    std::cout << "How many? ";
    int count{getInt()};
    std::cout << "Factor? ";
    int factor{getInt()};
    std::cout << "I generated " << count << " numbers. Do you know each number is after multiplying it by " << factor << '\n';
    for (int i{0}; i < count; i++)
    {
        numList.push_back((start + i) * (start + i) * factor);
    }
    int guess{};
    while (true)
    {
        std::cout << "Take a guess > ";
        guess = getInt();
        auto find{std::find(numList.begin(), numList.end(), guess)};
        if (find == numList.end())
        {
            if (std::abs(findClosestNumber(numList, guess) - guess) <= 4)
                std::cout << guess << " is wrong! Try " << findClosestNumber(numList, guess) << " next time!\n";
            else
            {
                std::cout << guess << " is Wrong!\n";
                break;
            }
        }
        else
        {
            count--;
            std::cout << "Nice! " << count << " numbers left!\n";
            numList.erase(find);
            if (count <= 0)
            {
                std::cout << "You have guessed all the numbers!\n";
                break;
            }
        }
        // for(auto a:numList)
        //     std::cout<<a<<' ';
        // std::cout<<'\n';
    }

    return 0;
}
