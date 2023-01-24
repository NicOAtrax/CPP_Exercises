#pragma once
#include <iostream>

class Kid
{
private:
    std::string _name;
    int _money;

public:
    Kid(std::string name, int money) : _name{name},
                                       _money{money}
    {
    }

    std::string get_name() const
    {
        return _name;
    }

    int get_money() const
    {
        return _money;
    }
};
