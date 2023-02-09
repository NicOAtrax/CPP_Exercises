#include "Pokemon.h"

Pokemon::Pokemon(const std::string &name) : _name{name},
                                            _id{next_id++}
{
}

Pokemon::Pokemon(const Pokemon &other) : _name{other._name},
                                         _id{next_id++}
{
}

std::string Pokemon::name() const
{
    return _name;
}

int Pokemon::id() const
{
    return _id;
}

Pokemon &Pokemon::operator=(const Pokemon &other)
{
    if (this == &other)
    {
        _name = other._name;
    }
    return *this;
}