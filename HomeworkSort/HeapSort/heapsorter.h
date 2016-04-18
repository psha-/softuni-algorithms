#ifndef HEAP_H
#define HEAP_H

#include <vector>

using namespace std;

// Max Heap
template<class T>
class Heapsorter
{
public:
    Heapsorter(vector<T> arr);

    T& operator[](size_t index) {
        return m_Rep[index];
    }

    inline size_t size()
    {
        return m_Rep.size();
    }

private:
    void Build();
    void Sort();
    T& PopFront();
    void HeapifyUp(size_t start);
    void HeapifyDown(size_t);

    inline int Parent(size_t child) {
        return (child-1)/2;
    }
    inline size_t LeftChild(size_t parent) {
        return 2*parent+1;
    }
    inline size_t RightChild(size_t parent) {
        return 2*parent+2;
    }

    std::vector<T> m_Rep;
    size_t m_Length;
};

#endif // HEAP_H
