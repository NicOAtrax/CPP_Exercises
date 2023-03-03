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

std::unique_ptr<ArrayNode> ArrayNode::make_ptr(std::vector<NodePtr> data)
{
    auto result   = std::make_unique<ArrayNode>();
    result->_data = std::move(data);
    return result;
}

void ArrayNode::push_back(NodePtr node)
{
    _data.push_back(std::move(node));
}

size_t ArrayNode::height() const
{
    if (child_count() == 0)
    {
        return 0u;
    }
    size_t result = 0u;
    for (const auto& child : _data)
    {
        auto child_height = child->height();
        if (child_height > result)
        {
            result = child_height;
        }
    }
    return result + 1;
}

size_t ArrayNode::node_count() const
{
    size_t result = 1u;
    for (const auto& child : _data)
    {
        result += child->node_count();
    }
    return result;
}