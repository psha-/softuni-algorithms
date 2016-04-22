#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


void DevidePresents(vector<int> &presents, vector<int> &devided, int &diff, int &sum1, int &sum2)
{
    sort(presents.rbegin(), presents.rend());
    diff = 0;
    sum1 = 0;
    sum2 = 0;

    for( int present : presents ) {
        if( diff < 0 ) {
            diff += present;
            sum1 += present;
        }
        else {
            devided.push_back(present);
            diff -= present;
            sum2 += present;
        }
    }
    diff = abs(diff);
}

int main()
{
    string present;
    auto presents = vector<int>();
    string input;
    getline(cin, input);
    istringstream ss(input);

    while(getline(ss, present, ',')) {
        presents.push_back(stoi(present));
    }
    auto devided = vector<int>();
    int diff;
    int sum1 = 0;
    int sum2 = 0;

    DevidePresents(presents, devided, diff, sum1, sum2);

    cout << "Difference: " << diff << endl;
    cout << "Alan:" << sum2 << " Bob:" << sum1 << endl;
    cout << "Alan takes: ";
    for( int alanP : devided ) {
        cout << alanP << ' ';
    }
    cout << endl;
    cout << "Bob takes the rest." << endl;

    return 0;
}

