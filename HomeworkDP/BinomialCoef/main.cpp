#include <iostream>
#include <vector>

using namespace std;

vector<vector<long>> memos;

int BinomialCoef( int n, int k)
{
    if( k == -1 || k == n+1 ) {
        return 0;
    }
    if( 0 == n || 1 == n ) {
        return 1;
    }
    if( memos[n].size() == 0 ) {
        memos[n] = vector<long>(n+1, 0);
    }
    if( memos[n][k] == 0 ) {
        memos[n][k] = BinomialCoef(n-1, k-1) + BinomialCoef(n-1, k);
    }
    return memos[n][k];
}

int main()
{

    int n, k;
    cout << "n = "; cin >> n;
    cout << "k = "; cin >> k;

    if( k < 0 || k > n ) {
        cout << "k: 0 <= k <= n" << endl;
        return 1;
    }

    memos = vector<vector<long>>(n+1, vector<long>());

    cout << BinomialCoef(n, k) << endl;

    return 0;
}

