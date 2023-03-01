#pragma once

#include "Leaf.hpp"

#include <string>

class StringLeaf : public Leaf
{
private:
    std::string _data;

public:
    StringLeaf(std::string data)
        : Leaf { NodeKind::STRING }
        , _data { data }
    {}

    std::string        print() const override { return "\"" + _data + "\""; }
    const std::string& data() const { return _data; }
};