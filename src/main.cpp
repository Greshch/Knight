#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
#include <time.h>
using namespace std;

#define LACK_OF_ARGS -1

const int SIZE = 8;
const int ROWS = SIZE;
const int COLS = SIZE;
const int CELLS = ROWS * COLS;

//int count = 0;

int board[ROWS][COLS]
{

};
// x -first y - second
vector<pair<int, int>> const steps
{
        //A pure choice consequence
        /*{2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {-1, 2},
         {1, 2}*/

        //Good consequence especially for {0,0}, {3,0}, {7,7}
        {-2, 1},
        {-1, 2},
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
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

bool is_fill_board(int fill_cells)
{
    return fill_cells == CELLS;
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
    static int cells = 0;
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

    //cout << "$$ {col=" << col << ", row=" << row << endl;
    cells++;
    board[from.second][from.first] = cells;

    if (is_fill_board(cells))
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
    /*if (cells >= 62)
    {
        ++count;
        cout << "#" << cells << (count % 40 == 0 ? "\n" : " ");
        count %= 40;
    }*/
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
    time_t  start;
    time(&start);
    fill_board(begin_v);
    print_board();
    time_t  end;
    time(&end);
    //cout << "\n\tSolution had been find by " << end - start << " sec.\n";
    return 0;
}