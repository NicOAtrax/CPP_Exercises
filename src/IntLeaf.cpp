#include "IntLeaf.hpp"

static std::unique_ptr<IntLeaf> make_ptr(int data)
{
    return std::make_unique<IntLeaf>(data);
}