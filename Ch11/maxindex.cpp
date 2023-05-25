#include <iostream>
#include <iterator> // for std::size

int main()
{
    constexpr int scores[]{84, 92, 76, 81, 56};

    int maxScore{0}; // Assume our largest score is 0 to start
    int maxIndex{0};

    // now look for a larger score in the full array
    for (int student{0}; student < static_cast<int>(std::size(scores)); ++student)
    {
        if (scores[student] > maxScore)
        {
            maxScore = scores[student];
            maxIndex = student;
        }
    }

    std::cout << "The best score was " << maxScore << " and its index is " << maxIndex << '\n';

    return 0;
}