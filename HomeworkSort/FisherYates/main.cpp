#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template<class T>
void FisherYates(vector<T> &arr)
{
    for( auto i=0; i<arr.size(); i++){
        auto r = rand() % ( arr.size() - i ) + i;
        swap(arr[i], arr[r]);
    }
}

int main()
{

//    auto arr = vector<int>({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30});
    //auto arr = vector<char>({'c','o','o','l'});

    vector<int> arr = vector<int>();
    int number;
    string line;

    cout << "Fisher-Yates shuffle. Enter numbers separated by spaces: ";
    getline(std::cin, line);
    istringstream stream(line);
    while (stream >> number)
        arr.push_back(number);

    FisherYates(arr);

    for( auto n : arr ) cout << n << ' ';
    cout << endl;

    return 0;
}

