#include <iostream>
#include <string_view>
#include <iterator>

void playFizzBuzz(int round, int arraySize, int *ptrDiv, std::string_view *ptrWord)
{
    for (int index{0}; index < round; index++)
    {
        int state{false};
        for (int j{0}; j < arraySize; j++)
        {
            if ((index + 1) % ptrDiv[j] == 0)
            {
                if (!state)
                    state = true;
                std::cout << ptrWord[j];
            }
        }

        if (!state)
            std::cout << (index + 1);
        std::cout << '\n';
    }
}
int main()
{
    int divisors[]{3, 5, 7, 11, 13, 17, 19};
    std::string_view words[]{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
    static_assert(std::size(divisors) == std::size(words));

    int round{150};
    int arraySize = static_cast<int>(std::size(divisors));
    playFizzBuzz(round, arraySize, divisors, words);

    return 0;
}
