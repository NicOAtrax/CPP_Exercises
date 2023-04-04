#include "ex1.hpp"

#include <list>

void pairwise_concatenate(std::list<std::list<int>>& list1, const std::list<std::list<int>>& list2)
{
    auto i = list2.begin();
    for (auto& lst : list1)
    {
        concatenate(lst, *i);
        i++;
    }
}

void pairwise_concatenate(std::list<std::list<int>>& list1, std::list<std::list<int>>&& list2)
{
    auto i = list2.begin();
    for (auto& lst : list1)
    {
        if (i == list2.end())
        {
            return;
        }
        concatenate(lst, std::move(*i));
        i++;
    }

    while (i != list2.end())
    {
        list1.push_back(std::move(*i));
        i++;
    }
}