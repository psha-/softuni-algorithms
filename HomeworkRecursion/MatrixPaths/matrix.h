#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

struct Cell {
    enum Values {_, s, x, e};

    Values Value;
    bool Visited = false;

    Cell(Values val=_):Value(val)
    {}
};

class Matrix
{
public:
    Matrix(std::vector<std::vector<Cell>>);
    bool FindStart(unsigned int &, unsigned int &);
    void PrintPaths(unsigned int row, unsigned int col, std::vector<char> &path, char dir);
private:
    std::vector< std::vector<Cell>> m_Cells;

    bool IsValid(unsigned int row, unsigned int col) {
        return row < m_Cells.size() && col < m_Cells[row].size();
    }

    bool IsFree(unsigned int row, unsigned int col) {
        return IsValid(row, col) && 0 == m_Cells[row][col].Value;
    }

    bool IsEnd(unsigned int row, unsigned int col) {
        return IsValid(row, col) && Cell::e == m_Cells[row][col].Value;
    }

    bool IsVisited(unsigned int row, unsigned int col)
    {
        return IsValid(row, col) && true == m_Cells[row][col].Visited;
    }
};

#endif // MATRIX_H
