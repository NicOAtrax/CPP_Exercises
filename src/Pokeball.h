#pragma once
#include <iostream>
#include <string>
#include "Pokemon.h"

// A ball where a Pokemon sleeps.
class Pokeball
{
private:
    PokemonPtr _pokemon;

public:
    Pokeball();
    bool empty() const;
    void store(PokemonPtr pokemon);
    const Pokemon &pokemon() const;
};
