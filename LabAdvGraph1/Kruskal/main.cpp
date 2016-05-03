#include <iostream>
#include <vector>
#include <algorithm>
//#include <exception>

using namespace std;

namespace Graph {

    auto Parents = vector<int>();

    struct Edge {
        Edge(int start, int end, int weight):Start(start),End(end),Weight(weight)
        {}

        int Weight;
        int Start;
        int End;

        bool operator<(const Edge &rhs) const
        {
            return Weight < rhs.Weight;
        }

    };

    ostream& operator<<(ostream& os, const Edge& edge)
    {
        os << "(" << edge.Start << " " << edge.End << ") -> " << edge.Weight;
        return os;
    }

    void SetRoot(int node, int root)
    {
        Parents[node] = root;
    }

    int FindRoot(int node)
    {
        return Parents[node];
    }

    vector<Edge*> Kruskal(int numVertices, vector<Edge> &edges)
    {
        auto minSpanForest = vector<Edge*>();

        for( int i=0; i<numVertices; i++) {
            Parents.push_back(i);
        }

        sort(edges.begin(), edges.end());

        for( auto pE = edges.begin(); pE != edges.end(); pE++ ) {
            auto rootS = FindRoot(pE->Start);
            auto rootE = FindRoot(pE->End);
            if( rootE == rootS ) {
                continue;
            }
            if( rootS == pE->Start ) {
                SetRoot(pE->Start, rootE);
            }
            else {
                SetRoot(pE->End, rootS);
            }
            minSpanForest.push_back(&(*pE));

        }
        return minSpanForest;
    }


}

int main()
{
    using namespace Graph;

    int numVertices = 9;
    auto graphEdges = vector<Edge>({
                                       Edge(0,3,9),
                                       Edge(0,5,4),
                                       Edge(0,8,5),
                                       Edge(1,4,8),
                                       Edge(1,7,7),
                                       Edge(2,6,12),
                                       Edge(3,5,2),
                                       Edge(3,6,8),
                                       Edge(3,8,20),
                                       Edge(4,7,10),
                                       Edge(6,8,7),
                                   });

    auto minSpanForest = Kruskal(numVertices, graphEdges);
    for( auto edge : graphEdges ) {
        cout << edge << endl;
    }
    cout << endl;
    for( auto edge : minSpanForest ) {
        cout << *edge << endl;
    }
}

