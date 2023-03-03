#pragma once

#include "Node.hpp"

class Leaf : public Node
{
private:
public:
    Leaf(NodeKind kind)
        : Node(kind)
    {}

    size_t height() const { return 0u; }
    size_t node_count() const { return 1u; }
};