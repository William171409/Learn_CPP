#include <sstream> // for std::stringstream
#include <string>
#include <string_view>
#include <array>

#ifndef POTION_HPP
#define POTION_HPP

class Potion
{
public:
    // All possible types of potions
    enum PotionType
    {
        health,
        strength,
        poison,

        // For random potion generation
        max_type
    };

    enum PotionSize
    {
        small,
        medium,
        large,

        max_size
    };


private:
    PotionType m_type{};
    PotionSize m_size{};

public:
    Potion(PotionType type, PotionSize size)
        : m_type{ type },
        m_size{ size }
    {
    }

    PotionType getType() const { return m_type; }
    PotionSize getSize() const { return m_size; }

    // The names of potions are compile-time literals, we can
    // return a std::string_view.
    static std::string_view getPotionTypeName(PotionType type)
    {
        static constexpr std::array names{
          "Health",
          "Strength",
          "Poison"
        };

        return names.at(static_cast<std::size_t>(type));
    }

    static std::string_view getPotionSizeName(PotionSize size)
    {
        static constexpr std::array names{
          "Small",
          "Medium",
          "Large"
        };

        return names.at(static_cast<std::size_t>(size));
    }

    std::string getName() const
    {
        // We use a std::stringstream, but this could also be solved using
        // std::string.
        // We first used std::stringstream in lesson 7.13.
        std::stringstream result{};

        result << getPotionSizeName(getSize()) << " potion of " << getPotionTypeName(getType());

        // We can extract the string from an std::stringstream by using the str()
        // member function.
        return result.str();
    }

    static Potion getRandomPotion();
    // {
    //     return {
    //       static_cast<PotionType>(getRandomNumber(0, static_cast<int>(PotionType::max_type) - 1)),
    //       static_cast<PotionSize>(getRandomNumber(0, static_cast<int>(PotionSize::max_size) - 1))
    //     };
    // }
};

#endif