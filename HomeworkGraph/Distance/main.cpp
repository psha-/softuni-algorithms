#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

namespace Graph {
    vector<vector<int>> G;
    vector<bool> Visited;
    vector<int> Prev;
    int Found;

    void Init()
    {
        Graph::Visited = vector<bool>(Graph::G.size(), false);
        Prev = vector<int>(Graph::G.size(), -1);
        Found = -1;
    }

    int CalcDistance()
    {
        if( Found == -1 ) {
            return -1;
        }
        auto distance = 0;
        while( Prev[Found] > -1 ) {
            Found = Prev[Found];
            distance++;
        }
        return distance;
    }

    void FindDistance(int start, int end)
    {
        auto queued = queue<int>();
        queued.push(start);
        Visited[start];
        while( queued.size() > 0 ) {
            start = queued.front();
            queued.pop();
            if( start == end) {
                Found = end;
                break;
            }

            for( int child : G[start] ) {
                if( Visited[child] ) {
                    continue;
                }
                Prev[child] = start;
                queued.push(child);
                Visited[child] = true;
            }
        }

    }

//    vector<int> Predecessors;
//    vector<set<int>> Dependency;

//    void DFS(int node)
//    {
//        if( Visited[node] ) {
//            return;
//        }
//        Visited[node] = true;
//        for( int child : G[node] ) {
//            DFS(child);
//        }
//        cout << node << " ";
//    }

//    void Populate()
//    {
//        int n;

//        cin >> n;
//        cin.ignore();

////        Predecessors = vector<int>(n, 0);
//        Visited = vector<bool>(n, false);
////        Dependency.push_back(set<int>());
//        G = vector<vector<int>>();
//        G.reserve(n);

//        for( int node=0; node<n; node++) {
//            cout << node << " = ";
//            G.push_back(vector<int>());
//            string line;
//            int child;
//            getline(cin, line);
//            istringstream ss(line);
//            while( ss >> child) {
//                G[node].push_back(child);
//                if( Predecessors[node] == 0 ) {
//                    Dependency[0].insert(node);
//                }
//                if( Predecessors[child] > 0 ) {
//                    Dependency[Predecessors[child]].erase(child);
//                }
//                Predecessors[child]++;
//                while( Predecessors[child] >= Dependency.size() ) {
//                    Dependency.push_back(set<int>());
//                }
//                Dependency[Predecessors[child]].insert(child);
//            }
//        }
//    }

}

int main()
{
    Graph::G = vector<vector<int>>({
                                       {},
                                       {12, 21, 7},
                                       {},
                                       {},
                                       {12, 1},
                                       {},
                                       {},
                                       {21},
                                       {},
                                       {},
                                       {},
                                       {4},
                                       {4,9},
                                       {},
                                       {14},
                                       {},
                                       {},
                                       {},
                                       {},
                                       {1,21},
                                       {},
                                       {14,31},
                                       {},
                                       {},
                                       {},
                                       {},
                                       {},
                                       {},
                                       {},
                                       {},
                                       {},
                                       {},
                                    });
    Graph::Init();
    Graph::FindDistance(11,7);
    cout << Graph::CalcDistance() << endl;

    Graph::Init();
    Graph::FindDistance(11,21);
    cout << Graph::CalcDistance() << endl;


    Graph::Init();
    Graph::FindDistance(21,4);
    cout << Graph::CalcDistance() << endl;

    Graph::Init();
    Graph::FindDistance(19,14);
    cout << Graph::CalcDistance() << endl;

    Graph::Init();
    Graph::FindDistance(1,4);
    cout << Graph::CalcDistance() << endl;

    Graph::Init();
    Graph::FindDistance(1,11);
    cout << Graph::CalcDistance() << endl;

    Graph::Init();
    Graph::FindDistance(31,21);
    cout << Graph::CalcDistance() << endl;

    Graph::Init();
    Graph::FindDistance(11,14);
    cout << Graph::CalcDistance() << endl;

}
