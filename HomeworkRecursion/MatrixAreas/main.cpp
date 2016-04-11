#include <iostream>
#include <set>
#include "matrix.cpp"

using namespace std;

struct Area {
    unsigned int Row;
    unsigned int Col;
    unsigned int Value;

    Area(unsigned int row, unsigned int col, unsigned int value)
        :Row(row),Col(col),Value(value)
    {}

    struct Compare {
        bool operator() (Area* const lhs, Area* const rhs) const{
            if( lhs->Value != rhs->Value ) {
                return lhs->Value > rhs->Value;
            }
            if( lhs->Row != rhs->Row ) {
                return lhs->Row < rhs->Row;
            }
            return lhs->Col < rhs->Col;
        }
    };

};


void GetMatrixAreas(Matrix &m, set<Area *, Area::Compare> &areas)
{
    for( unsigned int row = 0; row < m.m_Rows; row++) {
       for( unsigned int col = 0; col < m.m_Cols; col++) {
          int value = 0;
          m.FindArea(row, col, value);
          if( value > 0 ) {
              Area *area = new Area(row, col, value);
              areas.insert(area);
          }
       }
    }
}

void PrintAreas(set<Area *, Area::Compare> areas)
{
    int i=1;
    for( Area *area : areas ) {
        cout << "Area #" << i++ << " at (" << area->Row << ", " << area->Col << "), size: " << area->Value << endl;
    }
}

int main()
{


    cout << "Mat1" <<endl;
    Matrix mat1 = Matrix({
         {Cell(), Cell(), Cell(), Cell(Cell::x), Cell(),        Cell(), Cell(),        Cell(Cell::x), Cell()},
         {Cell(), Cell(), Cell(), Cell(Cell::x), Cell(),        Cell(), Cell(),        Cell(Cell::x), Cell()},
         {Cell(), Cell(), Cell(), Cell(Cell::x), Cell(),        Cell(), Cell(),        Cell(Cell::x), Cell()},
         {Cell(), Cell(), Cell(), Cell(),        Cell(Cell::x), Cell(), Cell(Cell::x), Cell(),        Cell()}
    });
    set<Area *, Area::Compare> areas = set<Area *, Area::Compare>();
    GetMatrixAreas(mat1, areas);
    PrintAreas(areas);

    cout << "Mat2" <<endl;
    Matrix mat2 = Matrix({
         {Cell(Cell::x), Cell(), Cell(), Cell(Cell::x), Cell(),        Cell(),        Cell(),        Cell(Cell::x), Cell(), Cell()},
         {Cell(Cell::x), Cell(), Cell(), Cell(Cell::x), Cell(),        Cell(),        Cell(),        Cell(Cell::x), Cell(), Cell()},
         {Cell(Cell::x), Cell(), Cell(), Cell(Cell::x), Cell(Cell::x), Cell(Cell::x), Cell(Cell::x), Cell(Cell::x), Cell(), Cell()},
         {Cell(Cell::x), Cell(), Cell(), Cell(Cell::x), Cell(),        Cell(),        Cell(),        Cell(Cell::x), Cell(), Cell()},
         {Cell(Cell::x), Cell(), Cell(), Cell(Cell::x), Cell(),        Cell(),        Cell(),        Cell(Cell::x), Cell(), Cell()}
    });
    areas = set<Area *, Area::Compare>();
    GetMatrixAreas(mat2, areas);
    PrintAreas(areas);

    return 0;
}

