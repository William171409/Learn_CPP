#include <iostream>
#include "constants.hpp"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen{myConstants::gravity * seconds * seconds / 2};
    double heightNow{initialHeight - distanceFallen};

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

double calculateAndPrintHeight(double initialHeight, int time)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << '\n';
    return calculateHeight(initialHeight, time);
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight{};
    std::cin >> initialHeight;

    // for(int seconds{0};calculateHeight(initialHeight,seconds)>=0;seconds++)
    //     calculateAndPrintHeight(initialHeight, seconds);
    int seconds{0};
    while (true)
    {
        if (!calculateAndPrintHeight(initialHeight, seconds))
            break;
        // if(calculateHeight(initialHeight,seconds)==0)
        //     break;
        seconds++;
    }
    return 0;
}