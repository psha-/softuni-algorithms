//#ifndef PRIORITY_QUEUE_H
//#define PRIORITY_QUEUE_H

//#include <vector>
//#include <unordered_map>

//using namespace std;

//// Max Heap
//template<class T, typename Comparator>
//class PriorityQueue
//{
//public:
//    PriorityQueue():m_Length(),m_Rep(),m_Indexes()
//    {}
//    PriorityQueue(vector<T> arr):m_Length(arr.size()),m_Rep(arr),m_Indexes()
//    {
//        for( size_t current = 1; current < m_Length; current++ ) {
//            HeapifyUp(current);
//        }
//    }

////    T& operator[](size_t index) {
////        return m_Rep[index];
////    }

//    inline size_t Size()
//    {
//        return m_Length;
//    }
//    T& Pop()
//    {
//        auto popped = m_Rep[0];
//        m_Rep[0] = m_Rep[--m_Length];
//        HeapifyDown();
//        return popped;
//    }

//    void Push(T el)
//    {
//        m_Rep.push_back(el);
//        HeapifyUp(m_Length++);
//    }

//    bool TryDecreaseKey(T el)
//    {
//        auto existingEl = find(m_Rep.begin(), m_Rep.end(), el);
//        if( existingEl == m_Rep.end() ) {
//            return false;
//        }
//        m_Container.erase(existingEl);
//        m_Container.push_back(el);
//        make_heap(m_Rep.begin(), m_Rep.end(), Comparator());
//        return true;

//    }

//private:
//    int HeapifyUp(size_t start)
//    {
//        while( Parent(start) >= 0 && m_Rep[Parent(start)] < m_Rep[start] ) {
//            auto parent = Parent(start);
//            swap(m_Rep[parent], m_Rep[start]);

//            m_Indexes[m_Rep[start]] = parent;
//            m_Indexes[m_Rep[parent]] = start;

//            start = Parent(start);
//        }
//        return start;
//    }

//    void HeapifyDown(size_t index=0)
//    {
//        auto left = LeftChild(index);
//        auto right = RightChild(index);
//        size_t largest = index;

//        if( left < m_Length && m_Rep[left] > m_Rep[largest] ) {
//            largest = left;
//        }
//        if( right < m_Length && m_Rep[right] > m_Rep[largest] ) {
//            largest = right;
//        }
//        if( largest != index) {
//            swap(m_Rep[largest], m_Rep[index]);

//            m_Indexes[m_Rep[largest]] = index;
//            m_Indexes[m_Rep[index]] = largest;

//            HeapifyDown(largest);
//        }
//    }

//    inline int Parent(size_t child) {
//        return (child-1)/2;
//    }
//    inline size_t LeftChild(size_t parent) {
//        return 2*parent+1;
//    }
//    inline size_t RightChild(size_t parent) {
//        return 2*parent+2;
//    }

//    std::vector<T> m_Rep;
//    size_t m_Length;
//    std::unordered_map<T, int> m_Indexes;
//};

//#endif // PRIORITY_QUEUE_H


#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
//#include <unordered_map>
#include <algorithm>

template<class T, typename Comparator>
class PriorityQueue {
public:
    PriorityQueue():m_Container()
    {
        make_heap(m_Container.begin(), m_Container.end());
    }
    void Push(T el)
    {
        m_Container.push_back(el);
//        m_pEl.insert(el, &el);
        push_heap(m_Container.begin(), m_Container.end(), Comparator());
    }

    size_t Size()
    {
        return m_Container.size();
    }

    T Pop()
    {
        pop_heap(m_Container.begin(), m_Container.end(), Comparator());
        T el = m_Container.back();
        m_Container.pop_back();
//        m_pEl.erase(el);
        return el;
    }

    bool TryDecreaseKey(T el)
    {
//        if( m_pEl.find(el) == m_pEl.end() ) {
//            return false;
//        }
//        m_pEl[key] = newEl;
        auto existingEl = find(m_Container.begin(), m_Container.end(), el);
        if( existingEl == m_Container.end() ) {
            return false;
        }
        m_Container.erase(existingEl);
        m_Container.push_back(el);
        make_heap(m_Container.begin(), m_Container.end(), Comparator());
        return true;
    }

private:
//    std::unordered_map<TKey,*T> m_pEl;
    std::vector<T> m_Container;
};


#endif // PRIORITY_QUEUE_H
