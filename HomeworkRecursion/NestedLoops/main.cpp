#include <iostream>
#include <vector>

using namespace std;

void Loop(int nest, vector<int> &numbers, int level=0)
{
    if( level >= nest) {
        for( int number : numbers ) {
            cout << number << " ";
        }
        cout << endl;
        return;
    }
    for(int i=1; i<=nest; i++) {
        numbers.push_back(i);
        Loop(nest, numbers, level+1);
        numbers.pop_back();
    }

}

int main()
{
    int n;
    cout << "n=";
    cin >> n;

    vector<int> numbers = vector<int>();

    Loop(n, numbers);

    return 0;
}

