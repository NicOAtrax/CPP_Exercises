#pragma once

#include <string>
#include "Card.hpp"

enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field
};

inline std::string to_string(const SpellType type)
{
    switch (type)
    {
    case SpellType::Normal:
        return "Normal";
    case SpellType::Equip:
        return "Equip";
    case SpellType::Continuous:
        return "Continuous";
    case SpellType::QuickPlay:
        return "Quick-Play";
    case SpellType::Field:
        return "Field";
    }
    return "";
};

class Spell : public Card
{
private:
    SpellType _type;

public:
    Spell(std::string id, std::string name, SpellType type) : Card{std::move(id), CardType::Spell},
                                                              _type{type}
    {
        set_name(std::move(name));
    }

    SpellType get_spell_type() const
    {
        return _type;
    }
};