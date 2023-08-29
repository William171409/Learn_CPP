#include "random.hpp"
#include <iostream>
#include <array>
#include <string>
#include <string_view>

// IT's a good habit to add prefix m_ for member variables!
class Monster
{
public:
    enum MonsterType
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types,
    };
    static inline std::array name_list{"S1mple", "Twistzz", "M0nesy", "Niko", "degster", "Headtrick"};
    static inline std::array sound_list{"yoo", "yikes", "nahhh", "errrr", "hmm", "Wow"};

private:
    MonsterType m_t{};
    std::string m_name{};
    std::string m_roar{};
    int m_hp{};

public:
    Monster() = default;
    Monster(MonsterType type, std::string name, std::string roar, int hp) 
    : m_t{type}, m_name{name}, m_roar{roar}, m_hp{hp}
    {
    }
    std::string_view getTypeString(MonsterType type) const
    {
        switch (type)
        {
        case 0:
            return "dragon";
        case 1:
            return "goblin";
        case 2:
            return "ogre";
        case 3:
            return "orc";
        case 4:
            return "skeleton";
        case 5:
            return "troll";
        case 6:
            return "vampire";
        case 7:
            return "zombie";
        default:
            return "??????";
        }
    }
    void print() const
    {
        std::cout << m_name << " the " << getTypeString(m_t) << " has " << m_hp
                  << " hit points and says " << m_roar << '\n';
    }
};
namespace MonsterGenerator
{
    Monster generateMonster()
    {
        auto name{Monster::name_list[Random::get(0, Monster::name_list.size() - 1)]};
        auto sound{Monster::sound_list[Random::get(0, Monster::sound_list.size() - 1)]};

        return Monster{
            static_cast<Monster::MonsterType>(Random::get(0, Monster::max_monster_types - 1)),
            name, sound, 4};
    }
} // namespace MonsterGenerator

int main()
{
    Monster m{MonsterGenerator::generateMonster()};
    m.print();
    return 0;
}