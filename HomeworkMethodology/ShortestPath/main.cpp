#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <limits>
#include "priority_queue.h"

using namespace std;

namespace Matrix {
    struct Node {
        int Id;
        Node *Prev;
        int Value;
        int Sum;

        Node(int id, int value):Id(id),Value(value)
        {
            Prev = nullptr;
            Sum = numeric_limits<int>::max();
        }
    };

    struct NodeComparator
    {
        bool operator()(Node* lhs, Node* rhs)
        {
            return lhs->Sum > rhs->Sum;
        }
    };

    int Rows;
    int Cols;
    vector<vector<Node> > G;

    void Read()
    {

        cin >> Rows;
        cin >> Cols;

        G = vector<vector<Node> >(Rows*Cols, vector<Node>());


        auto rowBuffer = deque<int>();

        for(int r=0; r<Rows; r++) {
            for(int c=0; c<Cols; c++) {
                auto current = r*(Cols)+c;
                auto left = current - 1;
                auto top = current - Cols;
                int val;
                cin >> val;

                if( c > 0 ) {
                    G[current].push_back(Node(left, rowBuffer.back()));
                    G[left].push_back(Node(current, val));
                }
                if( rowBuffer.size() >= Cols ) {
                    G[current].push_back(Node(top, rowBuffer.front()));
                    G[top].push_back(Node(current, val));
                    rowBuffer.pop_front();
                }
                rowBuffer.push_back(val);
            }
        }
        // Make the sum to cell 0,0 - 0
        G[1][0].Sum = 0;
        G[Cols][0].Sum = 0;

        // Calculate the first sums
        G[0][0].Sum = G[0][0].Value + G[1][0].Value;
        G[0][1].Sum = G[0][1].Value + G[1][0].Value;
    }

    void PrintPath(Node* node)
    {
        int length = 0;
        auto path = stack<int>();
        while( node != nullptr ) {
            path.push( node->Value );
            length += node->Value;
            node = node->Prev;
        }
        path.push(G[1][0].Value);
        length += G[1][0].Value;

        cout << "Length: " << length << endl;
        cout << "Path: ";
        while(path.size() > 0) {
            cout << path.top() << ' ';
            path.pop();
        }
        cout << endl;
    }

    void CalculateShortestPath()
    {
        auto q = PriorityQueue<Node*, NodeComparator>();
        q.Push(&G[0][0]);
        q.Push(&G[0][1]);
        Node* node;
        while( q.Size() > 0 ) {
            node = q.Pop();

            if(node->Id == Rows*Cols-1) {
                break;
            }

            for( auto child_it = G[node->Id].begin(); child_it != G[node->Id].end(); child_it++) {
                if(node->Sum+child_it->Value < child_it->Sum) {
                    child_it->Sum = node->Sum+child_it->Value;
                    child_it->Prev = node;
                    if( !q.TryDecreaseKey(&(*child_it))) {
                        q.Push(&(*child_it));
                    }
                }
            }
        }
        PrintPath(node);
    }
}

int main()
{
    Matrix::Read();
    Matrix::CalculateShortestPath();
    return 0;
}

