#include <iostream>
#include <utility>
using namespace std;

const int ROWS = 8;
const int COLS = 8;

bool board[ROWS][COLS]
{

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

int main()
{
    print_board();
    return 0;
}