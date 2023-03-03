#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <iostream>
#include <memory>

class IntLeaf;
class StringLeaf;
class ArrayNode;
class ObjectNode;
class Node;

using NodePtr = std::unique_ptr<Node>;

class Node : public InstanceCounter
{
private:
    const NodeKind _kind;

public:
    Node(NodeKind kind)
        : _kind { kind }
    {}

    virtual std::string print() const = 0;

    NodeKind kind() const { return _kind; }
};