#ifndef SORTER_H
#define SORTER_H

#include <vector>

template<typename T> class Sorter
{
public:
    Sorter()
    {}
    virtual void Sort(std::vector<T> &collection) = 0;
};

#endif // SORTER_H
