#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
int InterpolationSearch(const vector<T> &arr, T val, size_t start, size_t end)
{
    if( start > end ) {
        return -1;
    }
    if( val < arr[start] || val > arr[end] ) {
        return -1;
    }
    int valFromStart = val - arr[start];

    float valToIndex = (float)( end - start ) / (arr[end] - arr[start]);

    size_t guess = start + valFromStart * valToIndex;

    if( val == arr[guess] ) {
        return guess;
    }
    if( val < arr[guess] ) {
        return InterpolationSearch(arr, val, start, guess-1);
    }
    return InterpolationSearch(arr, val, guess+1, end);
}

int main()
{
    vector<int> arr = vector<int>({1, 3, 5, 7, 9, 11, 14, 15});
    sort(arr.begin(), arr.end());

    int n;
    cout << "Number: "; cin >> n;
    cout << "Index: " << InterpolationSearch<int>(arr, n, 0, arr.size()-1) << endl;

    return 0;
}

