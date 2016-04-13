#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void PrintArr(const vector<int> &arr)
{
    int i = 0;
    while( i < arr.size()-1 ) {
        cout << arr[i] << ", ";
        i++;
    }
    cout << arr[i];
    cout << endl;
}

void Perm( vector<int> &arr, unsigned int index )
{
    if( index >= arr.size() ) {
        count++;
        PrintArr(arr);
        return;
    }
    for( unsigned int i = index; i < arr.size(); i++ ) {
        swap(arr[i], arr[index]);
        Perm(arr, index+1);
        swap(arr[i], arr[index]);
    }
}

int main()
{
    int n;
    cout << "n="; cin >> n;

    vector<int> arr = vector<int>();
    arr.reserve(n);
    for( int i=1; i<=n; i++) {
        arr.push_back(i);
    }

    Perm(arr, 0);

    cout << "Total permutations: " << count << endl;
    return 0;
}

