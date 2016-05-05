#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

template<class T>
class PriorityQueue {
public:
    PriorityQueue()
    {}
    void Push(T el)
    {
        m_Container.push_back(el);
        make_heap(m_Container.begin(), m_Container.end());
    }

    size_t Size()
    {
        return m_Container.size();
    }

    T Pop()
    {
        pop_heap(m_Container.begin(), m_Container.end());
        T el = m_Container.back();
        m_Container.pop_back();
        return el;
    }

    void DecreaseKey(T el)
    {
        make_heap(m_Container.begin(), m_Container.end());
    }

private:
    vector<T> m_Container;
};

namespace Graph {
    struct Child {
        Child(int value, double reliability):Value(value),Reliability(reliability)
        {}
        int Value;
        double Reliability;
    };

    bool operator <(const Child &lhs, const Child &rhs)
    {
        return lhs.Reliability > rhs.Reliability;
    }

    vector<vector<int>> Distances;
    vector<int> D;
    vector<int> Prev;

    vector<vector<Child>> G;

    void Populate(int &start, int &end)
    {
        int nodesNum, edgesNum;
        string separator;

        cout << "Nodes: ";
        cin >> nodesNum;

        cout << "Path: ";
        cin >> start >> ws >>separator >> ws >> end;

        cout << "Edges: ";
        cin >> edgesNum;

        G = vector<vector<Child>>();
        G.reserve(nodesNum);

        Prev = vector<int>(nodesNum, -1);

        for( auto i = 0; i < edgesNum; i++ ) {
            int parent, child;
            double reliability;
            cin >> parent >> ws >> child >> ws >> reliability;
            if( parent+1 > G.size() ) {
                G.resize(parent+1);
            }
            G[parent].push_back(Child(child, reliability));
        }
    }


    void Dijkstra(int start, int end)
    {
        {
            D  = vector<int>(Distances.size(), numeric_limits<int>::max());
            Prev = vector<int>(Distances.size(), -1);
            auto q = PriorityQueue<Child>();

            q.Push(Child(start,1));
            D[start] = 0;

            while(q.Size() > 0) {
                auto vertex = q.Pop();
                auto v = vertex.Value;
                if( v == end ) {
                    break;
                }

                // Add children
                for( auto c=0; c<Distances[v].size(); c++ ) {
                    if( Distances[v][c] == 0 ) {
                        continue;
                    }

                    if( D[c] == numeric_limits<int>::max() ) {
                        D[c] = D[v] + Distances[v][c];
                        Prev[c] = v;
                        auto vc = Child(c, D[c]);
                        q.Push(vc);
                    }
                    else if (D[v] + Distances[v][c] < D[c]) {
                        D[c] = D[v] + Distances[v][c];
                        Prev[c] = v;
                        //TODO:
//                        for( auto it=q.begin(); it!=q.end(); it++ ) {
//                            if( *it == el ) {
//                                it->Reliability = D[c];
//                                q.DecreaseKey(c);
//                                break;
//                            }
//                        }
                    }
                }
            }
        }
    }

    void PrintShortestTo(int node)
    {
        cout << "Distance from start to " << node << " is " << D[node] << endl;

        auto s = stack<int>();
        s.push(node);
        while( Prev[node] != -1 ) {
            s.push(Prev[node]);
            node = Prev[node];
        }

        cout << s.top();
        s.pop();
        while( s.size() > 0 ) {
            cout << " -> " << s.top();
            s.pop();
        }
        cout << endl;

    }

}

int main()
{
    int start, end;
    Graph::Populate(start, end);
    Graph::Dijkstra(start, end);
    Graph::PrintShortestTo(end);

    return 0;
}

