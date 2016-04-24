#ifndef SORTABLECOLLECTION_H
#define SORTABLECOLLECTION_H

#include "sorter.h"
#include <iostream>
#include <vector>

template<typename T>
class SortableCollection
{
public:
    SortableCollection()
    {}
    SortableCollection(std::vector<T> items):m_Items(items)
    {}
    unsigned int Count()
    {
        return m_Items.size();
    }

    void Sort(Sorter<T> *sorter)
    {
        sorter->Sort(m_Items);
    }

    int BinarySearch(T item);

    int InterpolationSearch(T item);

    int Shuffle();


private:
    std::vector<T> m_Items;

    friend std::ostream & operator<<(std::ostream & os, const SortableCollection &c)
    {
       for( T item : c.m_Items ) {
           os << item << ' ';
       }

       os << std::endl;

       return os;
    }
};

#endif // SORTABLECOLLECTION_H
