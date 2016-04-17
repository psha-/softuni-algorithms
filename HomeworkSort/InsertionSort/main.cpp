#include <iostream>
#include <vector>

using namespace std;

template<class T>
void PrintArr(const vector<T> &arr)
{
    for( T el : arr ) {
        cout << el << ' ';
    }
    cout << endl;
}

template<class T>
void InsertionSort(vector<T> &arr)
{
    for( size_t i=1; i < arr.size(); i++ ) {
        size_t j=i;
        while( arr[j-1] > arr[j] && j > 0 ) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

int main()
{
    vector<int> arr = vector<int>({-1, -3, -5, 4, 2, 22, 13});

    InsertionSort(arr);

    PrintArr(arr);
}

