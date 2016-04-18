#include "heapsorter.h"

template<class T>
Heapsorter<T>::Heapsorter(std::vector<T> arr)
    :m_Length(arr.size()),m_Rep(arr)
{
    Build();
    Sort();
}

template<class T>
T Heapsorter<T>::PopFront()
{
    auto popped = m_Rep[0];
    m_Rep[0] = m_Rep[--m_Length];
    HeapifyDown();
    return popped;
}

template<class T>
void Heapsorter<T>::Sort()
{
    while( m_Length > 0 ) {
        auto popped = PopFront();
        m_Rep[m_Length] = popped;
    }
}

template<class T>
void Heapsorter<T>::Build()
{
    for( size_t current = 1; current < m_Rep.size(); current++ ) {
        HeapifyUp(current);
    }
}

template<class T>
void Heapsorter<T>::HeapifyUp(size_t start)
{
    while( Parent(start) >= 0 && m_Rep[Parent(start)] < m_Rep[start] ) {
        swap(m_Rep[Parent(start)], m_Rep[start]);
        start = Parent(start);
    }
}

template<class T>
void Heapsorter<T>::HeapifyDown(size_t index=0)
{
    auto left = LeftChild(index);
    auto right = RightChild(index);
    size_t largest = index;

    if( left < m_Length && m_Rep[left] > m_Rep[largest] ) {
        largest = left;
    }
    if( right < m_Length && m_Rep[right] > m_Rep[largest] ) {
        largest = right;
    }
    if( largest != index) {
        swap(m_Rep[largest], m_Rep[index]);
        HeapifyDown(largest);
    }
}

template class Heapsorter<int>;
