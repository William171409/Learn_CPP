#include <iostream>
#include <random> // for std::mt19937
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool guessAnalysis(int guessNum, int answer)
{
    bool state{false};
    if (guessNum == answer)
    {
        std::cout << "Correct! You win!\n";
        state = true;
    }
    else if (guessNum > answer)
        std::cout << "Your guess is too high.\n";
    else
        std::cout << "Your guess is too low.\n";
    return state;
}

char getAns()
{
    char ch{};

    while (true)
    {
        std::cin >> ch;
        ignoreLine();
        if (ch == 'n' || ch == 'y')
            return ch;
        else
            std::cout << "Oops, that input is invalid.  Please try again: ";
    }
}

void playHilo(int magicNum)
{
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100."
                 "You have 7 tries to guess what it is."
              << '\n';

    bool state{true};

    for (int i{0}; i < 7; i++)
    {
        int guessNum{};

        while (true)
        {
            std::cout << "Guess#" << (i + 1) << ' ';
            std::cin >> guessNum;
            if (!std::cin || (guessNum < 1 || guessNum > 100)) // if the previous extraction failed
            {
                if (std::cin.eof()) // if the stream was closed
                {
                    exit(0); // shut down the program now
                }

                // let's handle the failure
                std::cin.clear(); // put us back in 'normal' operation mode
                ignoreLine();     // and remove the bad input
                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                ignoreLine(); // remove any extraneous input
                break;
            }
        }
        if (state == guessAnalysis(guessNum, magicNum))
        {
            state = false;
            break;
        }
    }

    if (state)
        std::cout << "Sorry, you lose. The correct number was " << magicNum << '\n';
}

int main()
{
    std::mt19937 mt{std::random_device{}()};

    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die10{1, 100}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };
    while (true)
    {
        playHilo(die10(mt));
        std::cout << "Would you like to play again (y/n)? ";
        if (getAns() == 'n') // getAns() must be either 'y' or 'n'
        {
            std::cout << "Thank you for playing!\n\n";
            break;
        }
    }

    return 0;
}
