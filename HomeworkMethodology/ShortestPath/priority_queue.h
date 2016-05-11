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
