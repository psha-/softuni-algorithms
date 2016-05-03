#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

namespace Universe {

    vector<int> U = vector<int>({1,2,3,4,5});

    struct Set {
        vector<int> elements = vector<int>();
        void Add(int el)
        {
            elements.push_back(el);
        }
        bool operator<(const Set &rhs) const {
            int match=0;
            int rMatch=0;
            for( auto pEl=elements.begin(); pEl != elements.end(); pEl++ ) {
                for( auto pU=U.begin(); pU != U.end(); pU++ ) {
                    if( *pEl == *pU ) {
                        match++;
                    }
                }
            }
            for( auto pREl=elements.begin(); pREl != elements.end(); pREl++ ) {
                for( auto pU=U.begin(); pU != U.end(); pU++ ) {
                    if( *pREl == *pU ) {
                        rMatch++;
                    }
                }
            }
            return match < rMatch;
        }
    };

    vector<Set> Sets = vector<Set>();

    void Populate()
    {
        int n;
        string line;

        cout << "Number of sets: ";
        cin >> n;

        for( int i=0; i<n; i++ ) {
            Sets.push_back(Set());
            int element;
            getline(cin, line);
            istringstream ss(line);

            while(ss >> element) {
                Sets[0].Add(element);
            }
        }
    }

}



int main()
{
    using namespace Universe;

    Populate();

    while( U.size() > 0 ) {
        sort(Sets.end(), Sets.begin());
        auto first = Sets.front();
//        for( auto el : first.elements ) {
    //        U.erase(el);
  //      }
    }

    cout << "Hello World!" << endl;
    return 0;
}

