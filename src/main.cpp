#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;

const int ROWS = 8;
const int COLS = 8;

const int STEP = 8;

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
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (board[i][j] == false)
            {
                return false;
            }
        }
    }
    return true;
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

void fill_board(pair<int,int> const& from)
{
    board[from.second][from.first] = 10;
    int i = 0;
    for (auto const& e : steps)
    {
        int col = from.first + e.first;
        int row = from.second + e.second;
        if (is_valid_coord({col, row}))
        {
            board[row][col] = ++i;
        }
    }
}


int main()
{
    print_board();
    fill_board({7, 7});
    print_board();
    return 0;
}