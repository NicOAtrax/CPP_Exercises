#pragma once

#include "Node.hpp"

#include <string>
#include <vector>

class ArrayNode : public Node
{
private:
    std::vector<NodePtr> _data;

public:
    ArrayNode()
        : Node { NodeKind::ARRAY }
    {}

    std::string print() const override;

    static std::unique_ptr<ArrayNode> make_ptr(std::vector<NodePtr> data = {});

    size_t child_count() const { return _data.size(); }

    void   push_back(NodePtr node);
    size_t height() const override;
    size_t node_count() const override;
};