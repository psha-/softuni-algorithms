#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace Matrix {
    vector<vector<char>> M;
    vector<vector<bool>> Visited;
    unordered_map<char, int> Areas;
    int AreasNum;

    void Populate()
    {
        int n;

        cout << "Number of rows: ";
        cin >> n;
        cin.ignore();

        M = vector<vector<char>>();
        Visited = vector<vector<bool>>();

        for( int i=0; i<n; i++) {
            M.push_back(vector<char>());
            Visited.push_back(vector<bool>());
            string line;
            char c;
            getline(cin, line);
            istringstream ss(line);
            while( ss >> c) {
                M[i].push_back(c);
                Visited[i].push_back(false);
            }
        }
    }

    bool IsNeighbor(int row, int col, int row1, int col1)
    {
        return M[row][col] == M[row1][col1];
    }

    bool OutsideBounds(int row, int col)
    {
        return row >= M.size() || col >= M[0].size();
    }

    bool IsAccessible(int row, int col, int row1, int col1)
    {
        return !OutsideBounds(row1, col1)
                && IsNeighbor(row, col, row1, col1)
                && !Visited[row1][col1];
    }

    void CheckCell(int row, int col)
    {
        Visited[row][col] = true;

        if( IsAccessible(row, col, row, col+1) ) {
            CheckCell(row, col+1);
        }
        if( IsAccessible(row, col, row+1, col) ) {
            CheckCell(row+1, col);
        }
        if( IsAccessible(row, col, row, col-1) ) {
            CheckCell(row, col-1);
        }
        if( IsAccessible(row, col, row-1, col) ) {
            CheckCell(row-1, col);
        }
    }

    void FindAreas()
    {
        Areas = unordered_map<char, int>();
        AreasNum = 0;
        for( int row=0; row<M.size(); row++) {
            for( int col=0; col<M[row].size(); col++) {
                if( !OutsideBounds(row, col) && !Visited[row][col] ) {
                    auto c = M[row][col];
                    if( Areas.find(c) == Areas.end() ) {
                        Areas.insert(pair<char, int>(c, 0));
                    }
                    Areas[c]++;
                    AreasNum++;
                    CheckCell(row, col);
                }
            }
        }
    }

}

int main()
{
    Matrix::Populate();
    Matrix::FindAreas();
    cout << "Areas: " << Matrix::AreasNum << endl;
    for( pair<char,int> area : Matrix::Areas ) {
        cout << "Letter '" << area.first << "' -> " << area.second << endl;
    }

    return 0;
}

