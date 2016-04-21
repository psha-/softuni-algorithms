#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int previ[100];

void PrintLongestSeq(const vector<int> &arr, size_t lastIndex)
{
    auto output = stack<int>();
    output.push(arr[lastIndex]);
    while( previ[lastIndex] != -1 ) {
        output.push(arr[previ[lastIndex]]);
        lastIndex = previ[lastIndex];
    }
    while( output.size() > 0 ) {
        cout << output.top() << ' ';
        output.pop();
    }
    cout << endl;
}

size_t GetLongestZigZagIndex(const vector<int> &arr)
{
    previ[0] = -1;
    size_t longestSeqIndex = 0;
    size_t longestSeqCount = 1;
    size_t count = 1;

    for( size_t index=1; index<arr.size(); index++ )
    {
        for( size_t rev = index-1; rev >= 0; rev-- ) {
            if( arr[index] == arr[rev] ) {
                continue;
            }
            if( previ[rev] != -1 ) {
                if( arr[index] > arr[rev] && arr[rev] > arr[previ[rev]]) {
                    continue;
                }
                if( arr[index] < arr[rev] && arr[rev] < arr[previ[rev]]) {
                    continue;
                }
            }
            previ[index] = rev;
            count++;
            if(count > longestSeqCount) {
                longestSeqCount = count;
                longestSeqIndex = index;
            }
            break;
        }

    }
    return longestSeqIndex;
}

int main()
{
    string token;
    auto arr = vector<int>();
    string input;
    getline(cin, input);
    istringstream ss(input);

    while(getline(ss, token, ',')) {
        arr.push_back(stoi(token));
    }
    size_t index = GetLongestZigZagIndex(arr);

    PrintLongestSeq(arr, index);
    return 0;
}

