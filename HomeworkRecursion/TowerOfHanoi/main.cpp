#include <iostream>
#include <stack>

using namespace std;

int stepsTaken = 0;
stack<int> Source = stack<int>();
stack<int> Spare = stack<int>();
stack<int> Destination = stack<int>();

void PrintRod(const stack<int> &rod)
{
    stack<int> dump;
    stack<int> reversed;

    dump = rod;
    while(dump.size() > 0) {
        reversed.push(dump.top());
        dump.pop();
    }
    while(reversed.size() > 0) {
        cout << reversed.top() << ' ';
        reversed.pop();
    }
    cout << endl;
}

void PrintRods()
{
    cout << "Source: ";
    PrintRod(Source);

    cout << "Destination: ";
    PrintRod(Destination);

    cout << "Spare: ";
    PrintRod(Spare);

    cout << endl;
}

void MoveDisks(int bottomDisk, stack<int> &source, stack<int> &destination, stack<int> &spare)
{
    if( 1 == bottomDisk ) {
        stepsTaken++;
        destination.push(source.top());
        cout << "Step# " << stepsTaken << ": Moved disk:" << source.top() << endl;
        source.pop();
        PrintRods();
    }
    else {
        MoveDisks(bottomDisk-1, source, spare, destination);
        stepsTaken++;
        destination.push(source.top());
        cout << "Step# " << stepsTaken << ": Moved disk:" << source.top() << endl;
        source.pop();
        PrintRods();
        MoveDisks(bottomDisk-1, spare, destination, source);
    }
}

int main()
{
    int disks;

    cin >> disks;

    for( int i=disks; i>0; i--) {
        Source.push(i);
    }

    PrintRods();
    MoveDisks(disks, Source, Destination, Spare);

}

