#pragma once
#include "../lib/Unit.hpp"

#include <set>

struct comparator
{
    bool operator()(Unit unit1, Unit unit2) const { return unit1.name < unit2.name; }
};

class Kitchen
{
private:
    std::set<Unit, comparator> _units;

public:
    const Unit& register_unit(Unit unit);
    const Unit* find_unit(const std::string& name);
};
