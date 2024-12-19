#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 9;

bool isValid(const vector<vector<int>> &board, int row, int col, int num)
{
    // Kiểm tra hàng
    for (int x = 0; x < SIZE; ++x)
    {
        if (board[row][x] == num)
        {
            return false;
        }
    }

    // Kiểm tra cột
    for (int x = 0; x < SIZE; ++x)
    {
        if (board[x][col] == num)
        {
            return false;
        }
    }

    // Kiểm tra ô vuông 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

int solveSudoku(vector<vector<int>> &board, int row, int col)
{
    if (row == SIZE - 1 && col == SIZE)
    {
        return 1; // Đã tìm thấy 1 cách giải
    }

    if (col == SIZE)
    {
        row++;
        col = 0;
    }

    if (board[row][col] != 0)
    {
        return solveSudoku(board, row, col + 1);
    }

    int count = 0;
    for (int num = 1; num <= SIZE; ++num)
    {
        if (isValid(board, row, col, num))
        {
            board[row][col] = num;
            count += solveSudoku(board, row, col + 1);
            board[row][col] = 0; // Quay lui
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> board(SIZE, vector<int>(SIZE));

    // Đọc input
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cin >> board[i][j];
        }
    }

    // Tính số lượng cách giải
    int solutions = solveSudoku(board, 0, 0);

    // Xuất kết quả
    cout << solutions << endl;

    return 0;
}
