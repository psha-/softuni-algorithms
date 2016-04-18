#include <iostream>
#include "heapsorter.h"

using namespace std;

int main()
{
    auto collection = Heapsorter<int>({1,6,2,8,5,6,2,87,9,0,2,3});
    for( int i = 0; i<collection.size(); i++ ) cout << collection[i] << ' ';
    cout << endl;

    return 0;
}

