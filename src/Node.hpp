#pragma once
#include "InstanceCounter.hpp"

#include <iostream>
#include <memory>

class Node;

using NodePtr = std::unique_ptr<Node>;

class Node : public InstanceCounter
{
private:
public:
};