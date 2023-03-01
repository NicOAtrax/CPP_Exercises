#include "ArrayNode.hpp"

std::string ArrayNode::print() const
{
    std::string res = "[";
    for (unsigned int i = 0; i < _data.size(); i++)
    {
        if (i > 0)
        {
            res += ";";
        }
        res += _data[i]->print();
    }
    res += "]";
    return res;
}