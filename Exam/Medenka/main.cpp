#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace Medenka {

    vector<bool> Nuts;

    void Input()
    {
        Nuts = vector<bool>();
        Nuts.reserve(30);

        char nut;
        string line;
        getline (cin, line);
        istringstream ss(line);
        while( ss >> nut ) {
            Nuts.push_back((int)(nut-'0'));
        }
    }

    void Cut( int start, vector<int> &cuts)
    {
        if(start>=Nuts.size()) {
            size_t i=0;
            for( ; i< cuts.size()-2; i++) {
                for(auto j=cuts[i]; j<cuts[i+1]; j++){
                    cout << Nuts[j];
                }
                cout << '|';
            }
            for(auto j=cuts[i]; j<cuts[i+1]; j++){
                cout << Nuts[j];
            }
            cout << endl;
            return;
        }

        auto nuts=0;
        auto i=start;
        while(i<Nuts.size()) {
            if(Nuts[i]) {
                nuts++;
            }
            if(nuts>1) {
                break;
            }
            i++;
            if( nuts==0 ) {
                continue;
            }
            cuts.push_back(i);
            Cut(i, cuts);
            cuts.erase(cuts.end()-1);
        }
    }
}

int main()
{
    Medenka::Input();

    auto cuts = vector<int>(1, 0);
    Medenka::Cut(0, cuts);

    return 0;
}

