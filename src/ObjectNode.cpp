#include "ObjectNode.hpp"

std::string ObjectNode::print() const
{
    std::string res = "{";
    for (auto const& val : _data)
    {}
    res += "}";
    return res;
}