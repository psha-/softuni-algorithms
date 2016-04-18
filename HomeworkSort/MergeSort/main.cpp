#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template<class T>
vector<T> Merge(const vector<T> left, const vector<T> right)
{
    vector<T> merged = vector<T>();
    merged.reserve(left.size()+right.size());

    auto l_it = left.begin();
    auto r_it = right.begin();

    while(l_it != left.end() && r_it != right.end()) {
        if( *l_it < *r_it ) {
            merged.push_back(*(l_it++));
        }
        else {
            merged.push_back(*(r_it++));
        }
    }

    while( l_it != left.end() ) {
        merged.push_back(*(l_it++));
    }
    while( r_it != right.end() ) {
        merged.push_back(*(r_it++));
    }

    return merged;
}

template<class T>
vector<T> MergeSort(vector<T> &arr, size_t start, size_t end)
{
    if( start == end ) {
        return vector<T>({arr[start]});
    }
    size_t mid = start + ( end - start ) / 2;

    vector<T> left = MergeSort(arr, start, mid);
    vector<T> right = MergeSort(arr, mid+1, end);
    return Merge(left, right);
}


int main()
{
//    auto arr = vector<char>({'c','f','d','e','y','u','g','h','i','o','p','1','4','5','s','g','7'});
    vector<int> arr = vector<int>();
    int number;
    string line;

    cout << "Merge sort. Enter numbers separated by spaces: ";
    getline(std::cin, line);
    istringstream stream(line);
    while (stream >> number)
        arr.push_back(number);

    auto sorted = MergeSort(arr, 0, arr.size()-1);

    for( auto n : sorted ) cout << n << ' ';
    cout << endl;

    return 0;
}

