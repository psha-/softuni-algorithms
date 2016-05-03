#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
//#include <unordered_map>
#include <limits>
//#include <cmath>

using namespace std;

namespace Graph {
    struct Vertex {
        Vertex(int val, int d):Val(val),DStart(d)
        {}
        int Val;
        int DStart;

        operator int()
        {
            return Val;
        }
    };

    bool operator <(const Vertex &lhs, const Vertex &rhs)
    {
        return lhs.DStart > rhs.DStart;
    }

    vector<vector<int>> Distances;
    vector<int> D;
    vector<int> Prev;

    void PrintPathTo(int node)
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

    void FindShortestPaths(int start, int end)
    {
//        auto pV = vector<Vertex*>(Distances.size());
        D  = vector<int>(Distances.size(), numeric_limits<int>::max());
        Prev = vector<int>(Distances.size(), -1);
        auto q = vector<Vertex>();

        q.push_back(Vertex(start,0));
//        make_heap(q.begin(), q.end());
        D[start] = 0;
//        pV[0] = &q[0];
//        vIndexes.insert(pair<int, int>(start,0));

        while(q.size() > 0) {
            // Deque
            pop_heap(q.begin(), q.end());
            auto v = q.back();
            q.pop_back();
            if( v == end ) {
                break;
            }

            // Add children
            for( auto c=0; c<Distances[v].size(); c++ ) {
                if( Distances[v][c] == 0 ) {
                    continue;
                }

//                d[c] = min(d[c], d[v] + Distances[v][c]);
                if( D[c] == numeric_limits<int>::max() ) {
                    D[c] = D[v] + Distances[v][c];
                    Prev[c] = v;
                    auto vc = Vertex(c, D[c]);
//                    pV[c] = &vc;
                    q.push_back(vc);
                    push_heap(q.begin(), q.end());
//                    vIndexes.insert(pair<int, int>(c,d[c]));
                }
                else if (D[v] + Distances[v][c] < D[c]) {
                    D[c] = D[v] + Distances[v][c];
                    Prev[c] = v;
                    // Reorder heap
//                    pV[c]->DStart = D[c];
                    for( auto it=q.begin(); it!=q.end(); it++ ) {
                        if( *it == c ) {
                            it->DStart = D[c];
                            make_heap(q.begin(), q.end());
                            break;
                        }
                    }

                }
            }

        }
    }

}

int main()
{

    Graph::Distances = vector<vector<int>>({
                                            // 0   1   2   3   4   5   6   7   8   9  10  11
                                            { 0,  0,  0,  0,  0,  0, 10,  0, 12,  0,  0,  0 }, // 0
                                            { 0,  0,  0,  0, 20,  0,  0, 26,  0,  5,  0,  6 }, // 1
                                            { 0,  0,  0,  0,  0,  0,  0, 15, 14,  0,  0,  9 }, // 2
                                            { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  0 }, // 3
                                            { 0, 20,  0,  0,  0,  5, 17,  0,  0,  0,  0, 11 }, // 4
                                            { 0,  0,  0,  0,  5,  0,  6,  0,  3,  0,  0, 33 }, // 5
                                            {10,  0,  0,  0, 17,  6,  0,  0,  0,  0,  0,  0 }, // 6
                                            { 0, 26, 15,  0,  0,  0,  0,  0,  0,  3,  0, 20 }, // 7
                                            {12,  0, 14,  0,  0,  3,  0,  0,  0,  0,  0,  0 }, // 8
                                            { 0,  5,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0 }, // 9
                                            { 0,  0,  0,  7,  0,  0,  0,  0,  0,  0,  0,  0 }, // 10
                                            { 0,  6,  9,  0, 11, 33,  0, 20,  0,  0,  0,  0 }, // 11
                                        });

    Graph::FindShortestPaths(0, 9);
    Graph::PrintPathTo(9);

    return 0;
}

