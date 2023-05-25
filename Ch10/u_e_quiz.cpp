#include <iostream>
namespace monster
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}

int main()
{
    monster::MonsterType monster{ monster::troll };
    std::cout<<monster<<std::endl;

    return 0;
}