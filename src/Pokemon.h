#pragma once

#include <string>
#include <memory>

// A creature that is cute and can fight other ones.
class Pokemon
{
private:
    static inline int next_id = 0;
    std::string _name;
    int _id = 0;

public:
    Pokemon(const std::string &name);
    Pokemon(const Pokemon &other);
    std::string name() const;
    int id() const;
    Pokemon &operator=(const Pokemon &other);
};

using PokemonPtr = std::unique_ptr<Pokemon>;
