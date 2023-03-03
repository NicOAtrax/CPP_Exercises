#include "StringLeaf.hpp"

std::string StringLeaf::print() const
{
    return "\"" + _data + "\"";
}

std::unique_ptr<StringLeaf> StringLeaf::make_ptr(std::string s)
{
    return std::make_unique<StringLeaf>(std::move(s));
}