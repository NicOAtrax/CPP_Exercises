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
};