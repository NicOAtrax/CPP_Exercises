#include "Kitchen.hpp"

#include <utility>

const Unit& Kitchen::register_unit(Unit unit)
{
    auto [it, emplaced] = _units.emplace(std::move(unit));
    return *it;
}

const Unit* Kitchen::find_unit(const std::string& name)
{
    auto it = _units.find(Unit { name });
    if (it != _units.end())
    {
        return &(*it);
    }
    return nullptr;
}
