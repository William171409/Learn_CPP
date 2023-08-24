#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <random> // required for std::mt19937 engine

namespace Poker
{
    enum class Rank
    {
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        Jack,
        Queen,
        King,
        Ace,

        Max_number_rank,
    };

    enum class Suit
    {
        clubs,
        diamonds,
        hearts,
        spades,

        Max_number_suit,
    };
}

struct Card
{
    Poker::Suit suit{};
    Poker::Rank rank{};
};
void printCard(const Card &c)
{
    switch (c.rank)
    {
    case Poker::Rank::two:
        std::cout << '2';
        break;
    case Poker::Rank::three:
        std::cout << '3';
        break;
    case Poker::Rank::four:
        std::cout << '4';
        break;
    case Poker::Rank::five:
        std::cout << '5';
        break;
    case Poker::Rank::six:
        std::cout << '6';
        break;
    case Poker::Rank::seven:
        std::cout << '7';
        break;
    case Poker::Rank::eight:
        std::cout << '8';
        break;
    case Poker::Rank::nine:
        std::cout << '9';
        break;
    case Poker::Rank::ten:
        std::cout << "10";
        break;
    case Poker::Rank::Jack:
        std::cout << 'J';
        break;
    case Poker::Rank::Queen:
        std::cout << 'Q';
        break;
    case Poker::Rank::King:
        std::cout << 'K';
        break;
    case Poker::Rank::Ace:
        std::cout << 'A';
        break;

    default:
        std::cout << "Rank of the card not found!\n";
        break;
    }
    switch (c.suit)
    {
    case Poker::Suit::clubs:
        std::cout << 'C';
        break;
    case Poker::Suit::diamonds:
        std::cout << 'D';
        break;
    case Poker::Suit::hearts:
        std::cout << 'H';
        break;
    case Poker::Suit::spades:
        std::cout << 'S';
        break;

    default:
        std::cout << "Suit of the card not found!\n";
        break;
    }
    std::cout << ' ';
}

std::array<Card, 52> createDeck()
{
    std::array<Card, 52> deck{};
    for (int i{0}; i < static_cast<int>(Poker::Suit::Max_number_suit); i++)
    {
        for (int j{0}; j < static_cast<int>(Poker::Rank::Max_number_rank); j++)
        {
            deck[i * 13 + j].rank = static_cast<Poker::Rank>(j);
            deck[i * 13 + j].suit = static_cast<Poker::Suit>(i);
        }
    }
    return deck;
}

void printDeck(const std::array<Card, 52> &d)
{
    for (const Card &c : d)
    {
        printCard(c);
    }
}
void shuffleDeck(std::array<Card, 52> &d)
{
    std::mt19937 eng{std::random_device{}()}; // create a random number engine
    std::shuffle(d.begin(), d.end(), eng);
}
int getCardValue(Card card)
{
    if (card.rank != Poker::Rank::ten && card.rank != Poker::Rank::Jack && card.rank != Poker::Rank::Queen && card.rank != Poker::Rank::King &&
        card.rank != Poker::Rank::Ace)
        return (static_cast<int>(card.rank) + 2);
    else if (card.rank == Poker::Rank::Ace)
    {
        /* code */
        return 1;
    }
    else
    {
        return 10;
    }
}
bool playBlackjack(std::array<Card, 52> &poker_cards);
int main()
{
    std::array<Card, 52> decker_cards{createDeck()};
    printDeck(decker_cards);

    std::cout << "\nShuffle the decker cards: \n";
    shuffleDeck(decker_cards);

    printDeck(decker_cards);

    if (playBlackjack(decker_cards))
        std::cout << "Player wins!\n";
    else
        std::cout << "Dealer wins!\n";
    return 0;
}

void getDealerCard(std::vector<Card> &dealerSet, std::array<Card, 52> &poker_cards, int &index, int &sumDealer)
{
    // Draw a card for dealer and increment the index by 1 so that no repeated card is used
    dealerSet.push_back(poker_cards[index]);
    sumDealer += getCardValue(poker_cards[index]);
    //Ace justification 1 or 11!!!
    if((sumDealer+10)==21&&poker_cards[index].rank==Poker::Rank::Ace)
        sumDealer=21;
    index++;

    // Statistics of the cards and points
    std::cout << "Dealer's card set: ";
    for (const Card &c : dealerSet)
    {
        printCard(c);
    }
    std::cout << "\nDealer's point = " << sumDealer << std::endl;
}
void getPlayerCard(std::vector<Card> &playerSet, std::array<Card, 52> &poker_cards, int &index, int &sumPlayer)
{
    // Draw a card for dealer and increment the index by 1 so that no repeated card is used
    playerSet.push_back(poker_cards[index]);
    sumPlayer += getCardValue(poker_cards[index]);
    if((sumPlayer+10)==21&&poker_cards[index].rank==Poker::Rank::Ace)
        sumPlayer=21;
    index++;

    // Statistics of the cards and points
    std::cout << "Player's card set: ";
    for (const Card &c : playerSet)
    {
        printCard(c);
    }
    std::cout << "\nPlayer's point = " << sumPlayer << std::endl;
}

char hitORstand(char &ans)
{
    while (true)
    {
        std::cin >> ans;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (ans == 'h' || ans == 's')
            return ans;
        else
            std::cout << "Invalid input! Enter h(hit) or s(stand): ";
    }
}

bool playBlackjack(std::array<Card, 52> &poker_cards)
{
    std::vector<Card> dealerSet{};
    std::vector<Card> playerSet{};
    int index{};
    int sumDealer{0};
    int sumPlayer{0};
    char p_answer{};
    char d_answer{};

    for (int i{}; 2 > 0; i++)
    {
        if (i == 0)
        {
            std::cout << "\n\n*****ROUND" << i + 1 << "*****\n";
            getDealerCard(dealerSet, poker_cards, index, sumDealer);
            getPlayerCard(playerSet, poker_cards, index, sumPlayer);
            getPlayerCard(playerSet, poker_cards, index, sumPlayer);
            if (sumPlayer >= 21)
                return (sumPlayer == 21 ? true : false);

        }
        else
        {
            do
            {
                std::cout << "\n\n*****ROUND" << i++ + 1 << "*****\n";
                std::cout << "Player(hit or stand) h for hit ANY others for stand: ";
                if (hitORstand(p_answer) == 'h')
                    getPlayerCard(playerSet, poker_cards, index, sumPlayer);
                if (sumPlayer >= 21)
                    return (sumPlayer == 21 ? true : false);
            }while(p_answer!='s');
            

           
            if (sumDealer < 17)
            {
                do
                {
                std::cout << "\n\n*****ROUND" << i++ + 1 << "*****\n";

                    std::cout << "Dealer(hit or stand) h for hit Any others for stand: ";
                    if (hitORstand(d_answer) == 'h')
                        getDealerCard(dealerSet, poker_cards, index, sumDealer);
                    if (sumDealer >= 21)
                        return (sumDealer == 21 ? false : true);
                }while(sumDealer < 17)    ;       
            }

            d_answer = 's';
            std::cout << "Dealer's card set: ";
            for (const Card &c : dealerSet)
            {
                printCard(c);
            }
            std::cout << "\nDealer's point = " << sumDealer << std::endl;

            if (d_answer == 's' && p_answer == 's')
                return (sumPlayer > sumDealer ? true : false);
        }
    }
}