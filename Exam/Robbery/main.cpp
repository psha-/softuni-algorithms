#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>

template<class T, typename Comparator>
class PriorityQueue {
public:
    PriorityQueue():m_Container()
    {
        make_heap(m_Container.begin(), m_Container.end(), Comparator());
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
//        m_Container.erase(existingEl);
//        m_Container.push_back(el);
        make_heap(m_Container.begin(), m_Container.end(), Comparator());
        return true;
    }

private:
//    std::unordered_map<TKey,*T> m_pEl;
    std::vector<T> m_Container;
};


using namespace std;

namespace Robbery {
    vector<int> Costs;
    vector<int> Turns;
    vector<bool> Watched;
    vector<int> Prev;
    int W;
    int WaitingCost;
    int Start;
    int End;

    struct Edge{
        Edge(int end, int cost):End(end),Cost(cost)
        {}
        int End;
        int Cost;
    };

    struct NodeComparator
    {
        bool operator()(int lhs, int rhs)
        {
            return Costs[lhs] > Costs[rhs];
        }
    };

    vector<vector<Edge>> G;

    bool CanStep(int node)
    {
        return Watched[node] == Turns[node] % 2;
    }


    void Setup()
    {
        string line;
        string point;

        getline (cin, line);
        istringstream ss_line(line);
        int n = 0;
        while( ss_line >> point ) {
            istringstream ss_state(point);
            char state;
            int dummy;
            ss_state >> dummy >> state;
            Watched.push_back(state == 'w');
            n++;
        }
        cin >> W;
        cin >> WaitingCost;
        cin >> Start;
        cin >> End;
        G = vector<vector<Edge>>(n, vector<Edge>());
        Prev = vector<int>(n, -1);
        Turns= vector<int>(n, 0);
        Costs = vector<int>(n, numeric_limits<int>::max());
        Costs[Start] = 0;

        int e;
        cin >> e;
        for( auto i=0; i<e; i++) {
            int start;
            int end;
            int distance;
            cin >> start >> end >> distance;
            G[start].push_back(Edge(end, distance));
        }

    }

    void ShortestPath()
    {
        auto q = PriorityQueue<int, NodeComparator>();
        q.Push(Start);

        while( q.Size() > 0 ) {
            auto node = q.Pop();

            if(node == End) {
                break;
            }

            for( auto edge_it = G[node].begin(); edge_it != G[node].end(); edge_it++) {
                auto child = edge_it->End;
                Turns[child] = Turns[node]+1;
                auto newCost = Costs[node] + edge_it->Cost;
                if( !CanStep(child) ) {
                    newCost+=WaitingCost;
                    Turns[child]++;
                }
                if(newCost < Costs[child]) {
                    Costs[child] = newCost;
                    Prev[child] = node;
                    if( !q.TryDecreaseKey(child)) {
                        q.Push(child);
                    }
                }
            }
        }
    }
    void PrintShortest()
    {
        if( W >= Costs[End] ) {
            cout << W - Costs[End] << endl;
        }
        else {
            cout << "Busted - need " << Costs[End] - W << " more energy" << endl;
        }

    }
}

int main()
{
    Robbery::Setup();
    Robbery::ShortestPath();
    Robbery::PrintShortest();
    return 0;
}

