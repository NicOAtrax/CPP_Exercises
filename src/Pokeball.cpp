#include "Pokeball.h"

Pokeball::Pokeball() : _pokemon{nullptr}
{
}
bool Pokeball::empty() const
{
    return _pokemon == nullptr;
}
void Pokeball::store(PokemonPtr pokemon)
{
    _pokemon = std::move(pokemon);
}
const Pokemon &Pokeball::pokemon() const
{
    return *_pokemon;
}