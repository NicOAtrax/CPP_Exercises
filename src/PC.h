#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Pokemon.h"

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
private:
    std::vector<PokemonPtr> _pokemons;

public:
    std::vector<PokemonPtr> &pokemons();
    void transfer(PokemonPtr pokemon);
};
