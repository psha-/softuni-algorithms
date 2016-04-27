#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#define A_CAPITAL_ASCII 65

using namespace std;

namespace Graph {
    vector<vector<int>> G;
    vector<int> Predecessors;
    vector<set<int>> Dependency;

    void Populate()
    {
        char n_c;

        cout << "Enter biggest letter: ";
        cin >> n_c;
        int n = (int)n_c - A_CAPITAL_ASCII;

        cin.ignore();

        Predecessors = vector<int>(n+1, 0);
        Dependency.push_back(set<int>());
        G = vector<vector<int>>(n+1, vector<int>());
        G.reserve(n);

        cout << "Enter children letters: [A - B C ...]" << endl;

        for( int node=0; node<=n; node++) {
            cout << (char)(node + A_CAPITAL_ASCII) << " - ";
            string line;
            char child_c;
            getline(cin, line);
            istringstream ss(line);
            while( ss >> child_c) {
                int child = (int)child_c - A_CAPITAL_ASCII;
                G[node].push_back(child);
                G[child].push_back(node);
                Predecessors[child]++;
                Predecessors[node]++;
            }
        }
    }

    bool Acyclic()
    {
        int totalRemoved = 0;
        bool removed = true;
        while(removed) {
            removed = false;
            for( int node=0; node<Predecessors.size(); node++) {
                if( Predecessors[node] == 0 || Predecessors[node] == 1) {
                    totalRemoved++;
                    removed = true;
                    Predecessors[node] = -1;
                    for( auto child : G[node] ) {
                        Predecessors[child]--;
                    }
                }
            }
        }

        return totalRemoved == Predecessors.size();
    }
}

int main()
{
    Graph::Populate();
    cout << "Acyclic: " << ( Graph::Acyclic() ? "Yes" : "No" ) << endl;
}

