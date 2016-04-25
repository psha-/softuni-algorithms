#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

namespace SumCoins {
    vector<int> Coins = vector<int>();
    auto CoinNum = map<int, int>();
    auto memo = vector<vector<int>>();

    int GetCombinationsNum()
    {
        return *((*(memo.end()-1)).end()-1);
    }

    int CalculateUnlimitedCombinations(int sum)
    {
        for( auto c=0; c<Coins.size(); c++ ) {
            memo.push_back(vector<int>({1}));
        }
        for(auto s=1; s<=sum; s++) {
            memo[0].push_back((0 == sum%Coins[0])?1:0);
        }

        for(auto c=1; c<Coins.size(); c++) {
            for( auto s=1; s<=sum; s++ ) {
                auto whole = s/Coins[c];
                int comb=0;
                for( auto i=0; i<=whole; i++ ) {
                    auto reminder = s-i*Coins[c];
                    comb+= memo[c-1][reminder];
                }
                memo[c].push_back(comb);
            }
        }
    }

    int CalculateLimitedCombinations(int sum)
    {
        for( auto c=0; c<Coins.size(); c++ ) {
            memo.push_back(vector<int>({1}));
        }
        for(auto s=1; s<=sum; s++) {
            memo[0].push_back((s == Coins[0]));
        }

        for(auto c=1; c<Coins.size(); c++) {
            for( auto s=1; s<=sum; s++ ) {
                auto whole = min(s/Coins[c], CoinNum[Coins[c]]);
                int comb=0;
                for( auto i=0; i<=whole; i++ ) {
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

    int coin;
    string input;
    getline(cin, input);
    istringstream ss(input);

    while(ss >> coin) {
        if(SumCoins::CoinNum.find(coin) == SumCoins::CoinNum.end()) {
           SumCoins::Coins.push_back(coin);
           SumCoins::CoinNum[coin] = 0;
        }
        SumCoins::CoinNum[coin]++;
    }

    SumCoins::CalculateUnlimitedCombinations(s);

    cout << SumCoins::GetCombinationsNum() << endl;

    return 0;
}

