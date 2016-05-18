#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

namespace Sticks {
    struct NodeComparator {
        bool operator()(int a, int b) const {
            return a > b;
        }
    };

    set<int, NodeComparator> Free;
    vector<int> Picked;
    unordered_map<int, set<int, NodeComparator>> Dependencies;

    void Populate()
    {
        int n;
        int p;

        cin >> n;
        cin >> p;
        Dependencies = unordered_map<int, set<int, NodeComparator>>();
        Dependencies.reserve(3000);
        Free = set<int, NodeComparator>();

        for(auto i=0; i<n; i++) {
            Dependencies.insert(pair<int, set<int, NodeComparator>>(i, set<int, NodeComparator>()));
        }
        for(auto i=0; i<p; i++) {
            int child, parent;

            cin >> parent >> child;
            Dependencies[child].insert(parent);
        }
        for( auto node=0; node<Dependencies.size(); node++) {
            if( Dependencies[node].size() == 0 ) {
                Free.insert(node);
            }
        }
    }

    void Pick()
    {
        while(Free.size() > 0) {
            auto picked = Free.begin();
            auto picked_node = *picked;
            Free.erase(picked);
            Picked.push_back(picked_node);
            Dependencies.erase(picked_node);
            for(auto node=Dependencies.begin(); node!=Dependencies.end(); node++) {
                auto picked_dep = node->second.find(picked_node);
                if( picked_dep != node->second.end()) {
                    node->second.erase(picked_dep);
                }
                if( node->second.size() == 0 ) {
                    Free.insert(node->first);
                }
            }
        }
    }

    void Print()
    {
        if( Dependencies.size() > 0 ) {
            cout << "Cannot lift all sticks" << endl;
        }
        for(auto it = Picked.begin(); it != Picked.end(); it++ ) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

int main()
{
    Sticks::Populate();
    Sticks::Pick();
    Sticks::Print();
    return 0;
}

