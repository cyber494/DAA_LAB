#include <stdbool.h>
#include <stdio.h>
#define N 4
void printSolution(int board[N][N])
{
    printf("Solution 1 :\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}
void printRevSolution(int board[N][N])
{
    printf("Solution 2 :\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[N-i-1][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}
bool solveNQUtil(int board[N][N], int col)
{
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
int main(){
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
    printSolution(board);
    printRevSolution(board);
    return true;
    return 0;
}


// output:
// Solution 1 :
// . . Q . 
// Q . . .
// . . . Q
// . Q . .
// Solution 2 :
// . Q . .
// . . . Q
// Q . . .
// . . Q .