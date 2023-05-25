#include <iostream>
#include <array>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random> // required for std::mt19937 engine
void printCard(const Card &c);
void printDeck(const std::array<Card, 52> &d);
void shuffleDeck(std::array<Card, 52> &d);
int getCardValue(Card card);
