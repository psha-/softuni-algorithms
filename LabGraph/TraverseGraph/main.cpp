#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

namespace Graph {
    vector<vector<int>> G;
    vector<bool> Visited;
    vector<int> Predecessors;
    vector<set<int>> Dependency;

    void DFS(int node)
    {
        if( Visited[node] ) {
            return;
        }
        Visited[node] = true;
        for( int child : G[node] ) {
            DFS(child);
        }
        cout << node << " ";
    }

    void Populate()
    {
        int n;

        cin >> n;
        cin.ignore();

        Predecessors = vector<int>(n, 0);
        Visited = vector<bool>(n, false);
        Dependency.push_back(set<int>());
        G = vector<vector<int>>();
        G.reserve(n);

        for( int node=0; node<n; node++) {
            cout << node << " = ";
            G.push_back(vector<int>());
            string line;
            int child;
            getline(cin, line);
            istringstream ss(line);
            while( ss >> child) {
                G[node].push_back(child);
                if( Predecessors[node] == 0 ) {
                    Dependency[0].insert(node);
                }
                if( Predecessors[child] > 0 ) {
                    Dependency[Predecessors[child]].erase(child);
                }
                Predecessors[child]++;
                while( Predecessors[child] >= Dependency.size() ) {
                    Dependency.push_back(set<int>());
                }
                Dependency[Predecessors[child]].insert(child);
            }
        }
    }

    void PrintConnected()
    {
        for( int i=0; i<G.size(); i++) {
            cout << "Connected component: ";
            DFS(i);
            cout << endl;
        }
    }

    auto Sorted = vector<int>();

    bool TopoSort()
    {
        auto pChild = Dependency[0].begin();
        while( pChild != Dependency[0].end() ) {
            Sorted.push_back(*pChild);
            // Decrease child nodes dependecy with 1
            for( auto c : G[*pChild] ) {
                auto pC = Dependency[Predecessors[c]].find(c);
                Dependency[Predecessors[c]].erase(pC);
                if( Predecessors[c] > 0) {
                    Dependency[--Predecessors[c]].insert(c);
                }
            }
            Dependency[0].erase(pChild);
            pChild = Dependency[0].begin();
        }
        for( int i=0; i< Dependency.size(); i++ ) {
            if( Dependency[i].size() > 0 ) {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    Graph::Populate();
    Graph::PrintConnected();
    if( !Graph::TopoSort()) {
        cout << "The graph has cycles" << endl;
    }
    else {
        for( auto c : Graph::Sorted ) {
            cout << c << ' ';
        }
        cout << endl;
    }
}

