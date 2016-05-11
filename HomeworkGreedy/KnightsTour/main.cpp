#include <iostream>
#include <vector>

using namespace std;

namespace Chess {
    int N;
    vector<vector<int>> Moves;

    struct Pos {
        Pos(int row, int col):Row(row),Col(col)
        {}
        int Row;
        int Col;
    };

    void Init()
    {
        cin >> N;

        Moves = vector<vector<int>>();
        for( auto i=0; i<N; i++) {
            Moves.push_back(vecor<int>(N, 0));
        }
    }


    bool OnBoard(const Pos &pos) {
        return pos.Row >=0 && pos.Col >= 0 && pos.Row < N && pos.Col < N;
    }

    bool Occupied(const Pos &pos)
    {
        return Moves[pos.Row][pos.Col] != 0;
    }

    vector<Pos> NextMove(const Pos &prev, bool recursion=false)
    {
        auto moves = vector<pair<int, Pos>>();
        Pos move;

        move = Pos(prev.Row-2, col-1);
        if( OnBoard(move) && !Occupied(move) ) {
        }

    }

    void KnightsTour()
    {
        auto numMoves = 1;
        auto nextMove = Pos(0,0);
        while(nextMove.Row != -1) {
            Moves[nextMove.Row][nextMove.Col] = numMoves++;
            nextMove = NextMove(nextMove);
        }
    }
}

int main()
{
    Chess::Init();

    Chess::KnightsTour();
    return 0;
}

