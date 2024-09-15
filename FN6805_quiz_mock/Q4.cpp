#include <iostream>

int main()
{
    int sum{0};
    int n{};
    while (true)
    {
        std::cout << "Enter an integer in range [1,10] => ";
        std::cin >> n;
        sum += n;
        if (sum >= 100)
        {
            std::cout << "Congrats. You win!\n";
            break;
        }
        // Check forced win chance
        int diff{((sum - 1) / 11 + 1) * 11 + 1 - sum};
        if (diff < 1 || diff > 10)
        {
            // simply let it to be 1
            std::cout << "Computer input in range [1,10] => " << 1 << std::endl;
            sum += 1;
        }
        else
        {
            std::cout << "Computer input in range [1,10] => " << diff << std::endl;
            sum += diff;
            if (sum >= 100)
            {
                std::cout << "Sorry. PC wins!\n";
                break;
            }
        }
    }
    return 0;
}