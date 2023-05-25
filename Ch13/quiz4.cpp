#include <algorithm> // std::shuffle
#include <array>
#include <cassert>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937
// Maximum score before losing.
constexpr int g_maximumScore{ 21 };

// Minimum score that the dealer has to have.
constexpr int g_minimumDealerScore{ 17 };

class Card
{
public:
    enum CardSuit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum CardRank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };
private:
    CardRank m_rank{};
    CardSuit m_suit{};
public:
    Card()=default;
    Card(CardRank r, CardSuit s):m_rank{r},m_suit{s}{}

    int getCardValue()const
    {
        switch (m_rank)
        {
            case CardRank::rank_2:        return 2;
            case CardRank::rank_3:        return 3;
            case CardRank::rank_4:        return 4;
            case CardRank::rank_5:        return 5;
            case CardRank::rank_6:        return 6;
            case CardRank::rank_7:        return 7;
            case CardRank::rank_8:        return 8;
            case CardRank::rank_9:        return 9;
            case CardRank::rank_10:       return 10;
            case CardRank::rank_jack:     return 10;
            case CardRank::rank_queen:    return 10;
            case CardRank::rank_king:     return 10;
            case CardRank::rank_ace:      return 11;
            default:
                assert(false && "should never happen");
                return 0;
        }
    }
    void printCard()const
    {
        switch (m_rank)
        {
            case CardRank::rank_2:      std::cout << '2';   break;
            case CardRank::rank_3:      std::cout << '3';   break;
            case CardRank::rank_4:      std::cout << '4';   break;
            case CardRank::rank_5:      std::cout << '5';   break;
            case CardRank::rank_6:      std::cout << '6';   break;
            case CardRank::rank_7:      std::cout << '7';   break;
            case CardRank::rank_8:      std::cout << '8';   break;
            case CardRank::rank_9:      std::cout << '9';   break;
            case CardRank::rank_10:     std::cout << 'T';   break;
            case CardRank::rank_jack:   std::cout << 'J';   break;
            case CardRank::rank_queen:  std::cout << 'Q';   break;
            case CardRank::rank_king:   std::cout << 'K';   break;
            case CardRank::rank_ace:    std::cout << 'A';   break;
            default:
                std::cout << '?';
                break;
        }

        switch (m_suit)
        {
            case CardSuit::club:       std::cout << 'C';   break;
            case CardSuit::diamond:    std::cout << 'D';   break;
            case CardSuit::heart:      std::cout << 'H';   break;
            case CardSuit::spade:      std::cout << 'S';   break;
            default:
                std::cout << '?';
                break;
        }
    }

};


class Deck
{
private:
    std::array<Card,52> m_deck{};
    int m_cardIndex{0};
public:
    using Index = std::array<Card,52>::size_type;
    //This default constructor can be referred to original function createDeck()
    Deck()
    {
        Index index{ 0 };
        for (int suit{ 0 }; suit < (Card::max_suits); ++suit)
        {
            for (int rank{ 0 }; rank < (Card::max_ranks); ++rank)
            {
                m_deck[index]={static_cast<Card::CardRank>(rank),
                static_cast<Card::CardSuit>(suit)}; //Tricky!!!!
                ++index;
            }
        }
    }

    void printDeck()const
    {
        for (const auto& card : m_deck)
        {
            card.printCard();
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    void shuffleDeck()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        std::shuffle(m_deck.begin(), m_deck.end(), mt);

        m_cardIndex=0;
    }
    const Card& dealCard()
    {
        assert(m_cardIndex<m_deck.size());
        return m_deck[m_cardIndex++];
    }


};
class Player
{
    int m_score{};
public:
    int drawCard(Deck& deck)
    {
        int temp = deck.dealCard().getCardValue();
        m_score+=temp;
        return temp;
    }
    int score()const
    {
        return m_score;
    }
    bool isBust()const
    {
        return m_score>g_maximumScore;
    }


};



// Deck createDeck()
// {
//     Deck deck{};

//     // We could initialize each card individually, but that would be a pain.  Let's use a loop.

//     Index index{ 0 };

//     for (int suit{ 0 }; suit < static_cast<int>(CardSuit::max_suits); ++suit)
//     {
//         for (int rank{ 0 }; rank < static_cast<int>(CardRank::max_ranks); ++rank)
//         {
//             deck[index].suit = static_cast<CardSuit>(suit);
//             deck[index].rank = static_cast<CardRank>(rank);
//             ++index;
//         }
//     }

//     return deck;
// }


bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// // Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player)
{
    while (true)
    {
        if (player.isBust())
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                int cardValue{ player.drawCard(deck) };
                std::cout << "You were dealt a " << cardValue << " and now have " << player.score() << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// // Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.score() < g_minimumDealerScore)
    {
        int cardValue{ dealer.drawCard(deck) };
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score() << '\n';

    }

    // If the dealer's score is too high, they went bust.
    if (dealer.isBust())
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool playBlackjack(Deck& deck)
{
    // Index of the card that will be drawn next. This cannot overrun
    // the array, because a player will lose before all cards are used up.
    int nextCardIndex{ 0 };
    Player player{};
    Player dealer{};

    // Create the dealer and give them 1 card
    int dealerCard { dealer.drawCard(deck) };
    std::cout << "The dealer drew a card with value " << dealerCard << '\n';

    // Create the player and give them 2 cards.    
    int playerCard { player.drawCard(deck) };
    std::cout << "The player drew a card with value " << playerCard << '\n';
    playerCard = player.drawCard(deck);
    std::cout << "The player drew a card with value " << playerCard << '\n';

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    std::cout << "You have: " << player.score() << '\n';

    if (playerTurn(deck, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck,dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }
    
    return (player.score() > dealer.score())?true:((player.score() == dealer.score())?true:false);
}

int main()
{
    Deck deck{};
    deck.printDeck();
    deck.shuffleDeck();
    deck.printDeck();
    if(playBlackjack(deck))
    {
        std::cout<<"Player wins!\n";
    }
    else
    {
        std::cout<<"Dealer wins!\n";
    }

  return 0;
}
