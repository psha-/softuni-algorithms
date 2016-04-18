#include <iostream>
#include <sstream>
#include "heapsorter.h"

using namespace std;

int main()
{
    vector<int> arr = vector<int>();
    int number;
    string line;

    cout << "Heap sort. Enter numbers separated by spaces: ";
    getline(std::cin, line);
    istringstream stream(line);
    while (stream >> number)
        arr.push_back(number);

    auto collection = Heapsorter<int>(arr);
    for( int i = 0; i<collection.size(); i++ ) cout << collection[i] << ' ';
    cout << endl;

    return 0;
}

