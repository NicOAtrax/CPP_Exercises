#pragma once
#include <string>

enum class CardType
{
    Monster,
    Spell,
    Trap
};

inline std::string to_string(CardType type)
{
    switch (type)
    {
    case CardType::Monster:
        return "Monster";
    case CardType::Spell:
        return "Spell";
    case CardType::Trap:
        return "Trap";
    }

    return "";
}