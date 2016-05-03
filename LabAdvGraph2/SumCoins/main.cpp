#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    string line;
    int sum;
    int coin;

    auto coins = vector<int>();

    cout << "Coins: ";

    getline(cin, line);
    istringstream ss(line);

    while(ss>>coin) {
        coins.push_back(coin);
    }

    cout << "Sum: ";
    cin >> sum;

    sort(coins.begin(), coins.end());

    int totalTaken = 0;
    auto taken = map<int, int>();

    bool error = false;
    while( sum > 0 ) {
        while( coins.back() > sum ) {
            coins.pop_back();
            if( coins.size() <= 0 ) {
                error = true;
                break;
            }
        }
        if( error ) {
            break;
        }
        auto coin = coins.back();
        auto pack = sum / coin;
        sum -= pack*coin;
        if( taken.find(coin) == taken.end() ) {
            taken.insert(pair<int, int>(coin, 0));
        }
        totalTaken += pack;
        taken[coin] += pack;
    }

    if( error ) {
        cout << "Error" << endl;
        return 1;
    }
    cout << "Number of coins to take: " << totalTaken << endl;
    for( auto pCoin = taken.rbegin(); pCoin != taken.rend(); pCoin++ ) {
        cout << pCoin->second << " coin(s) with value " << pCoin->first << endl;
    }

    return 0;
}

