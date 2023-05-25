#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int main()
{
    std::array<Season, 4> seasons{
        {{"Spring", 285.0},
         {"Summer", 296.0},
         {"Fall", 288.0},
         {"Winter", 263.0}}};

    std::sort(seasons.begin(), seasons.end(), [](const auto &s1, const auto &s2)
              { return s1.averageTemperature < s2.averageTemperature; });
    for (const auto &season : seasons)
    {
        std::cout << season.name <<':'<<' '<<season.averageTemperature <<'\n';
    }

    return 0;
}