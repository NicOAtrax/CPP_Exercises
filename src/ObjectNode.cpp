#include "ObjectNode.hpp"

std::string ObjectNode::print() const
{
    std::string res = "{";
    for (auto const& val : _data)
    {}
    res += "}";
    return res;
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr(std::map<std::string, NodePtr> data)
{
    auto result   = std::make_unique<ObjectNode>();
    result->_data = std::move(data);
    return result;
}