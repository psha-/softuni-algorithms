#include <iostream>
#include <sstream>
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
    vector<int> arr = vector<int>();
    int number;
    string line;

    cout << "Insertion sort. Enter numbers separated by spaces: ";
    getline(std::cin, line);
    istringstream stream(line);
    while (stream >> number)
        arr.push_back(number);

    InsertionSort(arr);

    PrintArr(arr);
}

