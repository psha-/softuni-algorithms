#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void PrintArr(const vector<int> &arr)
{
    count++;
    unsigned int i = 0;
    while( i < arr.size()-1 ) {
        cout << arr[i] << ", ";
        i++;
    }
    cout << arr[i];
    cout << endl;
}

void Perm( int n )
{
    vector<int> arr = vector<int>();
    vector<int> p = vector<int>();
    arr.reserve(n);
    p.reserve(n+1);
    for( int i=0; i<n; i++) {
        arr.push_back(i+1);
        p.push_back(i);
    }
    p.push_back(n);

    int i=0;

    while( i < n ) {
        p[i]--;

        int j = i%2 > 0 ? p[i] : 0;
        swap(arr[j], arr[i]);
        i = 1;
        while( 0 == p[i] ) {
            p[i] = i;
            i++;
        }
        PrintArr(arr);
    }

}

int main()
{
    int n;
    cout << "n="; cin >> n;

    Perm(n);

    cout << "Total permutations: " << count << endl;
    return 0;
}

