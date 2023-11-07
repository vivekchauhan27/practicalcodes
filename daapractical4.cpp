//n queens
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    int N = board.size();
    for (int i = 0; i < row; i++)
        if (board[i][col] || (col - row + i >= 0 && board[i][col - row + i]) || (col + row - i < N && board[i][col + row - i]))
            return false;
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row) {
    int N = board.size();
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row)
            cout << (cell ? "Q " : ". ");
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0)) {
        cout << "Solution found:\n";
        printBoard(board);
    } else {
        cout << "No solution found.\n";
    }

    return 0;
}
