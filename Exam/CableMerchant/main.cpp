#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

namespace Jicata {
    vector<int> Prices;
    int ConnectorPrice;
    vector<vector<int>> Memo;

    void Input()
    {
        Prices = vector<int>(1, 0);

        string line;
        int price;

        getline (cin, line);
        istringstream ss(line);
        auto length = 1;
        while( ss >> price ) {
            Prices.push_back(price);
            length++;
        }
        cin >> ConnectorPrice;

    }

    void Optimize()
    {
        Memo = vector<vector<int>>(1, vector<int>(Prices.size(), 0));
        for( auto cut = 1; cut < Prices.size(); cut++) {
            Memo.push_back(vector<int>(1, 0));
            for(auto length=1; length<Prices.size(); length++) {
                auto price = 0;
                if( cut <= length ) {
                    auto connector = (cut == length ? 0 : ConnectorPrice*2);
                    price = Memo[cut][length-cut] + Prices[cut] - connector;
                }
                Memo[cut].push_back(max(price, Memo[cut-1][length]));
            }
        }
    }

    void PrintOptimal()
    {
        for( auto i = 1; i<Prices.size(); i++ ) {
            cout << Memo[Prices.size()-1][i] << ' ';
        }
        cout << endl;
    }

}

int main()
{

    Jicata::Input();
    Jicata::Optimize();
    Jicata::PrintOptimal();
    return 0;
}

