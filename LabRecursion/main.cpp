#include <iostream>
#include <vector>
#include <string>

using namespace std;

int FindSum( vector<double> &arr, unsigned int index=0)
{
    if( index >= arr.size() ) {
        return 0;
    }
    return arr[index] + FindSum( arr, index+1);
}


void PrintFigure(int count)
{
    if( 0 == count ) {
        return;
    }

    cout<<string(count, '*')<<"\n";

    PrintFigure(count - 1);

    cout<<string(count, '#')<<"\n";

}

void PrintVector(vector<int> &v)
{
    for( vector<int>::iterator  it = v.begin(); it != v.end(); it++ ) {
        cout<<*it;
    }
    cout<<"\n";
}

void Gen01(vector<int> &v, int n)
{
    if( -1 == n )
    {
        PrintVector(v);
        return;
    }

    for( int i=0; i<=1; i++) {
        v[n] = i;
        Gen01(v, n-1);
    }
}

int main()
{

    vector<double> numbers = vector<double>();
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    cout <<"The sum is "<<FindSum(numbers)<<"\n";

    PrintFigure(5);

    vector<int> v = vector<int>(4);

    Gen01(v, 4);
    return 0;
}

