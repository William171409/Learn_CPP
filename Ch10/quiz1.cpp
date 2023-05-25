/*Question #1

In designing a game, we decide we want to have monsters, because everyone likes fighting
monsters. Declare a struct that represents your monster. The monster should have a type that
can be one of the following: an ogre, a dragon, an orc, a giant spider, or a slime.
Use an enum class for this.Each individual monster should also have a name
(use a std::string or std::string_view), as well as an amount of health that represents
how much damage they can take before they die.
Write a function named printMonster() that prints out all of the struct’s members.
Instantiate an ogre and a slime, initialize them using an initializer list,
and pass them to printMonster().*/
#include <iostream>
#include <string>
#include <string_view> 
// Notice that to use std::string_view, the compiler must be in the version after C++17 

enum class Type_Monster
{
    orge,
    dragon,
    orc,
    giant_spider,
    slime,
};
struct Monster
{
    Type_Monster type{};
    std::string_view name{};
    int hp{};
};
std::string_view getTypename(Type_Monster t)
{
    switch (t)
    {
    case Type_Monster::orge:
        return "orge";
    case Type_Monster::dragon:
        return "dragon";
    case Type_Monster::orc:
        return "orc";
    case Type_Monster::giant_spider:
        return "giant_spider";
    case Type_Monster::slime:
        return "slime";
    default:
        return "???";
    }
}
//PASS by pointer using -> to get the member value
void printMonster(const Monster* m)
{
    std::cout << "Pass by pointer"<< std::endl;
    std::cout << "Monster's type = " << getTypename(m->type) << std::endl;
    std::cout << "Monster's name = " << m->name << std::endl;
    std::cout << "Monster's hp = " << m->hp << std::endl;
}

//PASS by reference using  . to get the member value
void printMonster(const Monster& m)
{
    std::cout << "Pass by reference"<< std::endl;
    std::cout << "Monster's type = " << getTypename(m.type) << std::endl;
    std::cout << "Monster's name = " << m.name << std::endl;
    std::cout << "Monster's hp = " << m.hp << std::endl;
}
//Notice that printMonster is overloaded and they are distinguished by referring to the number
// of arguments and type of arguments. It can't be distinguished using return data type                

int main()
{
    Monster monster{Type_Monster::giant_spider, "prince Edward", 100};
    Monster* p{&monster}; //pass by ptr
    Monster& ref{monster}; //pass by ref
    printMonster(p);
    return 0;
}
