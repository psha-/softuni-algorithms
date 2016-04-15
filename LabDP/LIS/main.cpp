#include <iostream>
#include <vector>
#include <stack>
#include <iterator>

using namespace std;

int len[100];
int previ[100];
int lastIndex = 0;

void PrintSeq(const vector<int> &seq)
{
    auto rev = stack<int>();
    rev.push(lastIndex);
    while( previ[lastIndex] > -1 ) {
        lastIndex = previ[lastIndex];
        rev.push(lastIndex);
    }

    while( rev.size() > 0 ) {
        cout << seq[rev.top()] << ' ';
        rev.pop();
    }

    cout << endl;
}

void CalcLIS(const vector<int> &seq)
{
    int maxLen = 1;
    for(int index=0; index < seq.size(); index++ ) {
        previ[index] = -1;
        len[index] = 1;
        int i=0;
        for(; i<index; i++){
            if( seq[i] < seq[index] && len[i]+1 > len[index]) {
                len[index] = len[i]+1;
                previ[index] = i;
            }
        }
        if( len[index] > maxLen ) {
            lastIndex = index;
            maxLen = len[index];
        }
    }
}

int main()
{
    //auto seq = vector<int>({11, 12, 13, 3, 14, 4, 15, 5, 6, 7, 8, 7, 16, 9, 8});
    //auto seq = vector<int>({3, 14, 5, 12, 15, 7, 8, 9, 11, 10, 1});
    //auto seq = vector<int>({7, 3, 5, 8, -1, 6, 7});

        vector<int> seq(
    std::istream_iterator<int>( std::cin ),
                           std::istream_iterator<int>());

    CalcLIS(seq);

    PrintSeq(seq);

    return 0;
}

