#include "ObjectNode.hpp"

std::string ObjectNode::print() const
{
    std::string res = "{";
    std::string sep = "";
    for (auto const& val : _data)
    {
        res += sep + '"' + val.first + "\":";
        res += val.second->print();
        sep = ",";
    }
    res += "}";
    return res;
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr(std::map<std::string, NodePtr> data)
{
    auto result   = std::make_unique<ObjectNode>();
    result->_data = std::move(data);
    return result;
}

size_t ObjectNode::height() const
{
    if (this->child_count() == 0)
    {
        return 0u;
    }
    size_t result = 0u;
    for (const auto& val : _data)
    {
        size_t child_height = val.second->height();
        if (child_height > result)
        {
            result = child_height;
        }
    }
    return result += 1u;
}

size_t ObjectNode::node_count() const
{
    size_t result = 1;
    for (const auto& child : _data)
    {
        result += child.second->node_count();
    }
    return result;
}