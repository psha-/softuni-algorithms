#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void ReverseArray(vector<int> &arr, unsigned int index=0)
{
    if( index >= arr.size()/2 ) {
        return;
    }
    int revIndex = arr.size() - index - 1;
    int tmp = arr[index];
    arr[index] = arr[revIndex];
    arr[revIndex] = tmp;
    ReverseArray(arr, index+1);
}

void ReadArray(vector<int> &arr)
{
    string line;
    int number;

    getline(cin, line);
    istringstream stream(line);
    while (stream >> number) {
        arr.push_back(number);
    }

}

int main()
{
    vector<int> numbers;

    ReadArray(numbers);

    ReverseArray(numbers);

    for( int number : numbers) {
        cout<<number<<" ";
    }
    cout<<endl;


    return 0;
}

