#include <iostream>
#include "sortablecollection.h"
#include "quicksorter.h"

using namespace std;

int main()
{
    auto collection = SortableCollection<int>({2, -1, 5, 0, -3});
    cout << collection;

    collection.Sort(new Quicksorter<int>());
    cout << collection;

    return 0;
}

