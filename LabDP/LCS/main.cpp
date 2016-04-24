#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

string FindLCS(const string &s1, const string &s2)
{
    auto memo = vector<vector<int>>();

    for( size_t i=0; i<=s1.size(); i++ ) {
        memo.push_back(vector<int>(s2.size()+1, 0));
    }

    for( size_t s1_i=1; s1_i<=s1.size(); s1_i++) {
        for(size_t s2_i=1; s2_i<=s2.size(); s2_i++) {
            int current;
            if( s1[s1_i-1] == s2[s2_i-1] ) {
                current = memo[s1_i-1][s2_i-1]+1;
            }
            else {
                current = max(memo[s1_i-1][s2_i], memo[s1_i][s2_i-1]);
            }
            memo[s1_i][s2_i] = current;
        }
    }

    // Recover LCS
    string lcs;

    {
        size_t s2_i = s2.size();
        size_t s1_i = s1.size();
        int current = memo[s1_i][s2_i];

        for( ; s1_i>0; s1_i-- ) {
            while(current == memo[s1_i][s2_i]) {
                s2_i--;
            }
            current = memo[s1_i][s2_i];
            lcs.push_back(s2[s2_i]);
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

    string lcs = FindLCS(s1, s2);
    cout << lcs << endl;

    return 0;
}

