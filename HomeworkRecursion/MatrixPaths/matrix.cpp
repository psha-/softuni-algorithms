#include "matrix.h"
#include <iostream>

Matrix::Matrix(std::vector<std::vector<Cell>> cells):m_Cells(cells)
{
}

void Matrix::PrintPaths(unsigned int row, unsigned int col, std::vector<char> &path, char dir)
{
    if( IsEnd(row, col)) {
        for( char move : path ) {
            std::cout << move << ' ';
        }
        std::cout << dir << std::endl;
        return;
    }
    if( !IsFree(row, col) ) {
        return;
    }
    if( IsVisited(row, col)) {
        return;
    }

    path.push_back(dir);
    m_Cells[row][col].Visited = true;

    PrintPaths(row+1, col, path, 'D');
    PrintPaths(row-1, col, path, 'U');
    PrintPaths(row, col+1, path, 'R');
    PrintPaths(row, col-1, path, 'L');

    path.pop_back();
    m_Cells[row][col].Visited = false;
}

bool Matrix::FindStart(unsigned int &row, unsigned int &col)
{
    for(unsigned int r=0; r < m_Cells.size(); r++){
        for(unsigned int c=0; c < m_Cells[r].size(); c++) {
            if( Cell::s == m_Cells[r][c].Value ) {
                row = r;
                col = c;
                return true;
            }
        }
    }
    return false;
}
