#pragma once
#include "Node.hpp"

#include <map>

class ObjectNode : public Node
{
private:
    std::map<std::string, NodePtr> _data;

public:
    ObjectNode()
        : Node { NodeKind::OBJECT }
    {}

    std::string print() const override;

    static std::unique_ptr<ObjectNode> make_ptr(std::map<std::string, NodePtr> data = {});
};