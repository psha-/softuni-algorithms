#include <iostream>
#include "matrix.h"

using namespace std;

void PrintMatrixAreas(Matrix &m)
{
    unsigned int startRow;
    unsigned int startCol;

    if( !m.FindStart(startRow, startCol)) {
        cout << "No start position defined" << endl;
    }

    vector<char> path = vector<char>();
    m.PrintPaths(startRow+1, startCol, path, 'D');
    m.PrintPaths(startRow-1, startCol, path, 'U');
    m.PrintPaths(startRow, startCol+1, path, 'R');
    m.PrintPaths(startRow, startCol-1, path, 'L');
}

int main()
{
    cout << "Mat1" <<endl;
    Matrix mat1 = Matrix({
        {Cell(Cell::s), Cell(),        Cell(),        Cell()},
        {Cell(),        Cell(Cell::x), Cell(Cell::x), Cell()},
        {Cell(),        Cell(Cell::x), Cell(Cell::x), Cell()},
        {Cell(),        Cell(Cell::x), Cell(Cell::e), Cell()},
        {Cell(),        Cell(),        Cell(),        Cell()}
    });
    PrintMatrixPaths(mat1);

    cout << "Mat2" <<endl;
    Matrix mat2 = Matrix({
        {Cell(Cell::s), Cell(),        Cell(),        Cell(),         Cell(),        Cell()},
        {Cell(),        Cell(Cell::x), Cell(Cell::x), Cell(),         Cell(Cell::x), Cell()},
        {Cell(),        Cell(Cell::x), Cell(Cell::x), Cell(),         Cell(Cell::x), Cell()},
        {Cell(),        Cell(Cell::x), Cell(Cell::e), Cell(),         Cell(),        Cell()},
        {Cell(),        Cell(),        Cell(),        Cell(Cell::x),  Cell(),        Cell()}
    });
    PrintMatrixPaths(mat2);

    return 0;
}

