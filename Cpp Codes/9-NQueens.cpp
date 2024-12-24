#include <bits/stdc++.h>
#define N 4

using namespace std;

void printSolution(const vector<vector<int>>& board) {
    cout << "solution 1 : \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}

void printrevSolution(const vector<vector<int>>& board) {
    cout << "solution 2 : \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[N - 1 - i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return false;
    }
    return true;
}

bool solveNQUtil(vector<vector<int>>& board, int col) {
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist";
        return 0;
    }
    printSolution(board);
    printrevSolution(board);
    return 0;
}
