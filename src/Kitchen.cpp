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

const Ingredient& Kitchen::register_ingredient(Ingredient ingr, Unit unit)
{
    auto [it, emplaced] = _ingredients.emplace(std::move(ingr));
    return *it;
}
const Ingredient* Kitchen::find_ingredient(const std::string& name)
{
    for (const auto& it : _ingredients)
    {
        if (it.name == name)
        {
            return &(*it);
        }
    }
    return nullptr;
}
