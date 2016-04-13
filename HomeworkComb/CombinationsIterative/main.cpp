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

void Comb(int n, int k)
{
    int com[100];
    for (int i = 0; i < k; i++) com[i] = i;
    while (com[k - 1] < n) {
        for (int i = 0; i < k; i++)
            cout << com[i]+1 << " ";
        cout << endl;

        int t = k - 1;
        while (t != 0 && com[t] == n - k + t) t--;
        com[t]++;
        for (int i = t + 1; i < k; i++) com[i] = com[i - 1] + 1;
    }
}

int main()
{
    int n;
    int k;
    cout << "n="; cin >> n;
    cout << "k="; cin >> k;

    Comb(n, k);

    return 0;
}

