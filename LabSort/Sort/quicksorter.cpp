#include "quicksorter.h"

template<typename T>
void Quicksorter<T>::Quicksort( std::vector<T> &items, int start, int end)
{
    if( start >= end ) {
        return;
    }
    int p = Partition( items, start, end );
    Quicksort(items, start, p);
    Quicksort(items, p+1, end);
}

template<typename T>
int Quicksorter<T>::Partition(std::vector<T> &items, int start, int end)
{
    int pivot = items[start];
    int storeIndex = start+1;

    for(int i=start+1; i<=end; i++)
    {
        if( items[i] < pivot ) {
            std::swap(items[i], items[storeIndex]);
            storeIndex++;
        }
    }
    storeIndex--;
    std::swap(items[start], items[storeIndex]);
    return storeIndex;

}

template class Quicksorter<int>;
