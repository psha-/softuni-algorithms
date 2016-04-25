#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace SumCoins {
    vector<int> Coins = vector<int>();
    auto memo = vector<vector<int>>();

    int GetCombinationsNum()
    {
        return *((*(memo.end()-1)).end()-1);
    }

    int CalculateLimitedCombinations(int sum)
    {
        for( auto c=0; c<Coins.size(); c++ ) {
            memo.push_back(vector<int>({1}));
        }
        for(auto s=1; s<=sum; s++) {
            memo[0].push_back(1);
        }

        for(auto c=1; c<Coins.size(); c++) {
            for( auto s=1; s<=sum; s++ ) {
                auto whole = s/Coins[c];
                int comb=0;
//                int comb = whole>0?1:0;
                //auto rem = s%Coins[c];
                for( auto i=0; i<=whole; i++ ) {
//                    comb++;
                    auto reminder = s-i*Coins[c];
                    comb+= memo[c-1][reminder];
                }
                memo[c].push_back(comb);
            }
        }

    }
}

int main()
{
    int s;
    cout << "S = "; cin >> s;
    cin.ignore();

    cout << "Coins = ";

    string token;
    string input;
    getline(cin, input);
    istringstream ss(input);

    while(getline(ss, token, ',')) {
        SumCoins::Coins.push_back(stoi(token));
    }

    SumCoins::CalculateLimitedCombinations(6);

    cout << SumCoins::GetCombinationsNum() << endl;

    return 0;
}

