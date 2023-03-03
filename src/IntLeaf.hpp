#pragma once

#include "Leaf.hpp"

class IntLeaf : public Leaf
{
private:
    int _data;

public:
    inline const int& data() const { return _data; }

    std::string print() const override { return std::to_string(_data); }

    static std::unique_ptr<IntLeaf> make_ptr(int data);

    IntLeaf(int data)
        : Leaf { NodeKind::INT }
        , _data { data } {};
};