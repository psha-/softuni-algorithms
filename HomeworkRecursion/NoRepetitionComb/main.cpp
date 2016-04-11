#include <iostream>
#include <vector>

using namespace std;

void Loop(const int &n, const int &k, vector<int> &numbers, int i=0, int level=0)
{
    if( level >= k) {
        for( int number : numbers ) {
            cout << number << " ";
        }
        cout << endl;
        return;
    }
    for(int j=i+1; j<=n; j++) {
        numbers.push_back(j);
        Loop(n, k, numbers, j, level+1);
        numbers.pop_back();
    }

}

int main()
{
    int n;
    int k;
    cout << "n="; cin >> n;
    cout << "k="; cin >> k;

    vector<int> numbers = vector<int>();

    Loop(n, k, numbers);

    return 0;
}

