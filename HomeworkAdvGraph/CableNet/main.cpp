#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace Graph {

    struct Edge {
        Edge(int start, int end, int weight, bool connected=false):Start(start),End(end),Weight(weight),Connected(connected)
        {}

        int Weight;
        int Start;
        int End;
        bool Connected;
    };

    struct EdgeComparator {
      bool operator() (Edge* arg1, Edge* arg2) {
        return arg1->Weight > arg2->Weight;
      }
    };

    vector<Edge> Edges;
    vector<vector<Edge*>> Children;
    vector<bool> Connected;
    int NumVertices;
    int Budget;
    int BudgetLeft;
    auto Q = priority_queue<Edge*, vector<Edge*>, EdgeComparator>();


    ostream& operator<<(ostream& os, const Edge& edge)
    {
        os << "{" << edge.Start << ", " << edge.End << "} -> " << edge.Weight;
        return os;
    }

    void Populate()
    {
        cout << "Budget: ";
        cin >> Budget;
        BudgetLeft = Budget;

        cout << "Nodes: ";
        cin >> NumVertices;

        int numEdges;
        cout << "Edges: ";
        cin >> numEdges;

        Edges = vector<Edge>();
        Edges.reserve(numEdges);

        Connected = vector<bool>(NumVertices, false);

        Children = vector<vector<Edge*>>(NumVertices, vector<Edge*>());

        cin.ignore();

        auto toEnque = vector<int>();

        for( auto i=0; i<numEdges; i++ ) {
            int start, end, weight;
            string connected;

            cin >> start >> ws >> end >> ws >> weight;

            Edges.push_back(Edge(start, end, weight));
            Children[start].push_back(&Edges.back());
            Children[end].push_back(&Edges.back());

            getline(cin, connected);
            if( connected == " connected" ) {
                toEnque.push_back(start);
                toEnque.push_back(end);
                Edges.back().Connected = true;
                Connected[start] = true;
                Connected[end] = true;
            }
        }

        for(auto node : toEnque) {
            for(auto edge = Children[node].begin(); edge != Children[node].end(); edge++) {
                if( (*edge)->Connected ) {
                    continue;
                }
                auto child = node == (*edge)->Start ? (*edge)->End : (*edge)->Start;
                // It can happen that also the child node is already connected with another edge
                if( Connected[child] ) {
                    continue;
                }
                (*edge)->Connected = true;
                Q.push(*edge);
            }
        }
    }

    vector<Edge*> Prim()
    {
        auto connected = vector<Edge*>();

        while( Q.size() > 0 ) {
            auto edge = Q.top();
            Q.pop();

            auto node = Connected[edge->Start] ? edge->End : edge->Start;
            if( Connected[node] ) {
                continue;
            }
            Connected[node] = true;
            for(auto it=Children[node].begin(); it!=Children[node].end(); it++ ) {
                auto child = node == (*it)->Start ? (*it)->End : (*it)->Start;
                if( Connected[child] ) {
                    continue;
                }
                if( (*it)->Connected ) {
                    continue;
                }
                Q.push(*it);
            }

            if( edge->Weight > BudgetLeft) {
                return connected;
            }
            BudgetLeft -= edge->Weight;
            edge->Connected = true;
            connected.push_back(edge);
        }

        return connected;
    }

}

int main()
{
    Graph::Populate();

    auto connected = Graph::Prim();
    for( auto edge : connected ) {
        cout << *edge << endl;
    }
    cout << "Budget used: " << Graph::Budget - Graph::BudgetLeft << endl;
}

