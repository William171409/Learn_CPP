#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <random>
#include <chrono> // for std::chrono::system_clock
#include "potion.hpp"

// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX
// int getRandomNumber(int min, int max)
// {
//     static constexpr double fraction{1.0 / (RAND_MAX + 1.0)}; // static used for efficiency, so we only calculate this value once
//     // evenly distribute the random number across our range
//     return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
// }

int getRandomNumber(int min, int max)
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

class Creature
{
protected:
    std::string m_name{};
    char m_symbol{};
    int m_hp{};
    int m_damage{};
    int m_gold{};

public:
    Creature(std::string_view name = "", char symbol = 0, int hp = 0, int damage = 0, int gold = 0)
        : m_name{name}, m_symbol{symbol}, m_hp{hp}, m_damage{damage}, m_gold{gold}
    {
    }
    const std::string &getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHp() const { return m_hp; }
    int getDamage() const { return m_damage; }
    int getGold() const { return m_gold; }

    void reduceHealth(int point) { m_hp -= point; }
    bool isDead() { return m_hp <= 0; }
    void addGold(int gold) { m_gold += gold; }
};

class Player : public Creature
{
    int m_level{1};

public:
    Player(std::string_view name = "", char symbol = '@', int hp = 10, int damage = 1, int gold = 0)
        : Creature(name, symbol, hp, damage, gold)
    {
        std::cout << "Welcome, " << m_name << '\n'
                  << "You have " << m_hp << " health and are carrying " << m_gold << " gold.\n";
    }

    void levelup()
    {
        m_level++;
        m_damage++;
    }
    int getLevel() const { return m_level; }

    void drinkPotion(const Potion &potion)
    {
        if (potion.getType() == Potion::health)
        {
            if (potion.getSize() == Potion::large)
                m_hp += 5;
            else
                m_hp += 2;
        }

        if (potion.getType() == Potion::strength)
            m_damage++;
        if (potion.getType() == Potion::poison)
            m_hp--;
    }
};

class Monster : public Creature
{

public:
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types,

    };

private:
    // As a private member of Monster
    static const Creature &getDefaultCreature(Type type)
    {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
            {{"dragon", 'D', 20, 4, 100},
             {"orc", 'o', 4, 2, 25},
             {"slime", 's', 1, 1, 10}}};

        return monsterData.at(static_cast<std::size_t>(type));
    }

public:
    Monster(Type type) : Creature{getDefaultCreature(type)}
    {
    }

    static const Monster getRandomMonster()
    {
        int num{getRandomNumber(0, static_cast<int>(Type::max_types) - 1)};
        // std::cout<<num<<std::endl;
        return Monster{static_cast<Type>(num)};
    }
};

Potion Potion::getRandomPotion()
{
    return {
        static_cast<PotionType>(getRandomNumber(0, static_cast<int>(PotionType::max_type) - 1)),
        static_cast<PotionSize>(getRandomNumber(0, static_cast<int>(PotionSize::max_size) - 1))};
}

// Function to generate a random 0(fail to escape) 1(escape successfully)
int randomZeroOrOne()
{
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number in the range [0, 1]
    int randomNum = std::rand() % 2;

    return randomNum;
}

bool attackMonster(Monster &m, int player_damamge)
{
    m.reduceHealth(player_damamge);
    std::cout << "You hit the " << m.getName() << " for " << player_damamge << " damage.\n";
    return m.isDead();
}

bool attackPlayer(Player &p, int monster_damamge, const std::string &m_name)
{
    p.reduceHealth(monster_damamge);
    std::cout << m_name << " hit you for " << monster_damamge << " damage.\n";
    return p.isDead();
}

bool fightMonster(Player &p, Monster &m)
{
    while (true)
    {
        std::cout << "(R)un or (F)ight: ";
        char decision{};
        std::cin >> decision;
        if (decision == 'f')
        {
            if (attackMonster(m, p.getDamage()))
            {
                std::cout << "You killed the " << m.getName() << '\n';
                break;
            }
            if (attackPlayer(p, m.getDamage(), m.getName()))
            {
                break;
            }
        }
        else
        {
            if (randomZeroOrOne())
            {
                std::cout << "You successfully fled.\n";
                return false;
            }
            else
            {
                std::cout << "You failed to flee.\n";
                if (attackPlayer(p, m.getDamage(), m.getName()))
                {
                    break;
                }
            }
        }
    }
    return true;
}

int main()
{
    // Create a player
    std::cout << "Enter your name: ";
    std::string playerName{};
    std::cin >> playerName;
    Player p1{playerName};

    while (true)
    {

        // Create a random monster at each level
        Monster m{Monster::getRandomMonster()};
        std::cout << "You have encountered a " << m.getName() << ' ' << '(' << m.getSymbol() << ')' << '\n';

        // bool repeat_level=fightMonster(p1,m);

        if (!fightMonster(p1, m))
            continue;

        if (p1.getHp() <= 0)
        {
            std::cout << "You died at level " << p1.getLevel() << " and with " << p1.getGold()
                      << " gold.\n"
                      << "Too bad you can’t take it with you!\n";
            break;
        }

        p1.levelup();
        p1.addGold(m.getGold());

        if (p1.getLevel() >= 20)
        {
            std::cout << "Congratualtions! You win the game with " << p1.getGold() << " gold.\n";
            break;
        }

        if (getRandomNumber(1, 10) <= 3)
        {
            std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
            char decision{};
            std::cin >> decision;
            if (decision == 'y')
            {
                Potion potion{Potion::getRandomPotion()};
                std::cout << "You drank a " << potion.getName() << '\n';
                p1.drinkPotion(potion);
            }
        }

        if (p1.getHp() <= 0)
        {
            std::cout << "You died at level " << p1.getLevel() << " and with " << p1.getGold()
                      << " gold.\n"
                      << "Too bad you can’t take it with you!\n";
            break;
        }






        std::cout << "You are now level " << p1.getLevel() << " with a damage of " << p1.getDamage() << " and a health of " << p1.getHp() << '\n'
                  << "You found " << p1.getGold()
                  << " gold.\n";
    }

    return 0;
}