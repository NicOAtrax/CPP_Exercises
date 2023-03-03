#include "IntLeaf.hpp"

std::unique_ptr<IntLeaf> IntLeaf::make_ptr(int data)
{
    return std::make_unique<IntLeaf>(data);
}