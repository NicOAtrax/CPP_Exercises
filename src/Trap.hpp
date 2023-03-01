#pragma once
#include <string>
#include "Card.hpp"

enum class TrapType
{
    Normal,
    Continuous,
    Counter
};

inline std::string to_string(const TrapType type)
{
    switch (type)
    {
    case TrapType::Normal:
        return "Normal";
    case TrapType::Continuous:
        return "Continuous";
    case TrapType::Counter:
        return "Counter";
    }
    return "";
};

class Trap : public Card
{
private:
    TrapType _type;

public:
    Trap(std::string id, std::string name, TrapType type) : Card{std::move(id), CardType::Trap},
                                                            _type{type}
    {
        set_name(std::move(name));
    }

    TrapType get_trap_type() const
    {
        return _type;
    }
};