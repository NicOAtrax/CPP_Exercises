#pragma once
#include <iostream>

class PlushStore
{

private:
    std::string _name;
    int _wealth_amount;
    int _stock_size;
    int _debt_amount;
    int _experience;

public:
    PlushStore(const std::string &name) : _name{name},
                                          _wealth_amount{0},
                                          _stock_size{0},
                                          _debt_amount{0},
                                          _experience{0}

    {
    }

    std::string get_name() const
    {
        return _name;
    }

    int get_wealth_amount() const
    {
        return _wealth_amount;
    }

    int get_stock_size() const
    {
        return _stock_size;
    }

    void loan(int amount)
    {
        _wealth_amount += amount;
        _debt_amount += (amount * 1.1);
    }

    int get_debt_amount() const
    {
        return _debt_amount;
    }

    int make_plush(int cost)
    {
        if (_wealth_amount > 0)
        {
            _stock_size++;
            _experience++;
            _wealth_amount = cost > _wealth_amount ? 0 : _wealth_amount - cost;
        }
        int const value = cost + std::max(_experience, cost * _experience / 100);
        return value;
    }

    int get_experience() const
    {
        return _experience;
    }
};