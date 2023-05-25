#include <iostream>
#include <string_view>

// int main()
// {
//     constexpr std::string_view names[]{"Alex", "Betty", "Caroline", "Dave", "Emily"}; // Names of the students
//     constexpr int scores[]{84, 92, 76, 81, 56};
//     int maxScore{0};

//     for (int i{0}; auto score : scores) // i is the index of the current element
//     {
//         if (score > maxScore)
//         {
//             std::cout << names[i] << " beat the previous best score of " << maxScore << " by " << (score - maxScore) << " points!\n";
//             maxScore = score;
//         }

//         ++i;
//     }

//     std::cout << "The best score was " << maxScore << '\n';

//     return 0;
// }
//Attention:There is no way that we can let user input a std::string_view as std::string_view cariable is not
//created with a memory
int main()
{
    std::string_view names[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::cout << "Enter a name: ";
    std::string magic{};
    std::getline(std::cin >>std::ws,magic);
    std::string_view magic_name{magic};
    for (std::string_view name : names)
    {
        if (name == magic_name)
        {
            std::cout << magic_name << " was found.\n";
            return 0;
        }
    }
    std::cout << magic_name << " was not found.\n";
}