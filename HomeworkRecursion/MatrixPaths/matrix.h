#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

struct Cell {
    enum Values {_, s, x, e};

    Values Value;
    bool Visited;

    Cell(Values val=_):Value(val),Visited(false)
    {}
};

class Matrix
{
public:
    Matrix(std::vector<std::vector<Cell>>);
    bool FindStart(unsigned int &, unsigned int &);
    void PrintPaths(unsigned int row, unsigned int col, std::vector<char> &path, char dir);
    void FindArea(unsigned int row, unsigned int col, int &area);
    unsigned int m_Rows;
    unsigned int m_Cols;
private:
    std::vector< std::vector<Cell>> m_Cells;

    bool IsValid(unsigned int row, unsigned int col) {
        return row < m_Rows && col < m_Cols;
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
