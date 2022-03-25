#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int ROWS = 8;
const int COLS = 8;

const int STEP = 8;

bool board[ROWS][COLS]
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
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
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
    &&     cell.second >= 0 && cell.second < ROWS
    && board[cell.second][cell.first] == false;
}

void fill_board(pair<int,int> const& from, pair<int,int> const& to)
{
    if (is_valid_coord(from))
    {

    }
    if (is_fill_board())
    {
        return;
    }
}


int main()
{
    print_board();
    return 0;
}