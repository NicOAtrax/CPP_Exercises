#include "Node.hpp"

class Leaf : public Node
{
private:
public:
    Leaf(NodeKind kind)
        : Node(kind)
    {}
};