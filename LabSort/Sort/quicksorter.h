#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include "sorter.h"

template<typename T> class Quicksorter : public Sorter<T>
{
public:
    Quicksorter()
    {}
    void Sort(std::vector<T> &collection)
    {
        Quicksort(collection, 0, collection.size()-1);
    }
private:
    int Partition(std::vector<T> &items, int start, int end);
    void Quicksort( std::vector<T> &items, int start, int end);
};

#endif // QUICKSORTER_H
