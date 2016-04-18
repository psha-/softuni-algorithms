#include <iostream>
#include <sstream>
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
    vector<int> arr = vector<int>();
    int number;
    string line;

    cout << "Interpolation search. Enter numbers separated by spaces: ";
    getline(std::cin, line);
    istringstream stream(line);
    while (stream >> number)
        arr.push_back(number);

    sort(arr.begin(), arr.end());

    cout << "Sorted:";
    for( int n : arr ) {
        cout << n << ' ';
    }
    cout << endl;

    int n;
    cout << "Number to find: "; cin >> n;
    cout << "Index: " << InterpolationSearch<int>(arr, n, 0, arr.size()-1) << endl;

    return 0;
}

