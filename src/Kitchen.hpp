#pragma once
#include "../lib/Ingredient.hpp"
#include "../lib/Unit.hpp"

#include <set>

struct comparator
{
    bool operator()(Unit unit1, Unit unit2) const { return unit1.name < unit2.name; }
    bool operator()(Ingredient ingr1, Ingredient ingr2) const { return ingr1.name < ingr2.name; }
};

class Kitchen
{
private:
    std::set<Unit, comparator>       _units;
    std::set<Ingredient, comparator> _ingredients;

public:
    const Unit&       register_unit(Unit unit);
    const Unit*       find_unit(const std::string& name);
    const Ingredient& register_ingredient(Ingredient ingr, Unit unit);
    const Ingredient* find_ingredient(const std::string& name);
};
