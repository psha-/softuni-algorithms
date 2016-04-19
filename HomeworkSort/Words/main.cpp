#include <iostream>
#include <sstream>
//#include <ctime>

#define LATIN_NUM 26
#define A_ASCII 97
#define MAX_CHARS 10

using namespace std;

int perm_count;

void permute(char arr[], size_t length, size_t index)
{
    if( index >= length ) {
        perm_count++;
        return;
    }

    bool swapped[LATIN_NUM] = {false};
    for( size_t i = index; i < length; i++ ) {
        char c = arr[i];
        if(swapped[c-A_ASCII]) {
            continue;
        }
        swapped[c-A_ASCII] = true;
        if( c == arr[index-1] ) {
            continue;
        }
        if( c == arr[index] ) {
            continue;
        }
        swap(arr[i], arr[index]);
        permute(arr, length, index+1);
        swap(arr[i], arr[index]);
    }
}

int main()
{
    string chars;
    char c;
    char arr[MAX_CHARS];
    size_t i=0;

//    clock_t total;
//    clock_t start;

    getline(std::cin, chars);

//    start = clock();

    istringstream stream(chars);
    while (stream >> c) {
        arr[i++] = c;

    }

    permute(arr, i, 0);

//    total = clock() - start;
    cout << perm_count << endl;
//    cout << "Time (sec): " << ((float)total)/CLOCKS_PER_SEC << endl;

    return 0;
}

