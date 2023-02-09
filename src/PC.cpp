#include "PC.h"

std::vector<PokemonPtr> &PC::pokemons()
{
    return _pokemons;
}
void PC::transfer(PokemonPtr pokemon)
{
    if (pokemon != nullptr)
    {
        _pokemons.push_back(std::move(pokemon));
    }
}