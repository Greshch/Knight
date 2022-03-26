#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;

#define LACK_OF_ARGS -1

const int SIZE = 6;
const int ROWS = SIZE;
const int COLS = SIZE;
const int CELLS = ROWS * COLS;

int cells = 0;

int board[ROWS][COLS]
{

};
// x -first y - second
vector<pair<int, int>> const steps
{
        {2, 1}, {2, -1},
        {1, -2}, {-1, -2},
        {-2, -1}, {-2, 1},
        {-1, 2}, {1, 2}
};

void print_board()
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            printf("%3d", board[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

bool is_fill_board()
{
    return cells == CELLS;
}

bool is_valid_coord(pair<int,int> const& cell)
{
    return cell.first >= 0 && cell.first < COLS
    &&     cell.second >= 0 && cell.second < ROWS;
}

bool is_empty_cell(pair<int,int> const& cell)
{
    return board[cell.second][cell.first] == false;
}

bool fill_board(pair<int,int> const& from)
{
    int col = from.first;
    int row= from.second;
    if ( !is_valid_coord({col, row }))
    {
        return false;
    }

    if (!is_empty_cell({col, row}))
    {
        return false;
    }

    cells++;
    board[from.second][from.first] = cells;

    if (is_fill_board())
    {
        return true;
    }
    //int i = 0;
    for (auto const& e : steps)
    {
        int dx = e.first;
        int dy = e.second;
        if ( fill_board({col + dx, row + dy}) == true )
        {
            return true;
        }
    }
    --cells;
    board[row][col] = false;
    return false;
}


int main(int argc, char** argv)
{
    if (argc < 3)
    {
        cerr << "Lack of data...ERROR...\n";
        return LACK_OF_ARGS;
    }
    pair<int,int> begin_v {stoi(argv[1]), stoi(argv[2])};
    fill_board(begin_v);
    print_board();
    return 0;
}