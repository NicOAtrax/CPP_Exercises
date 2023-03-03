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

    size_t child_count() const { return _data.size(); }

    void insert(std::string s, NodePtr node) { _data.emplace(std::move(s), std::move(node)); }

    size_t height() const override;
    size_t node_count() const override;
};