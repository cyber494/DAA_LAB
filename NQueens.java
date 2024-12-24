public class NQueens {
    final int N = 4;

    void printSolution(int board[][]) {
        System.out.println("Solution 1 :");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    System.out.print("Q ");
                else
                    System.out.print(". ");
            }
            System.out.println();
        }
    }

    void printRevSolution(int board[][]) {
        System.out.println("Solution 2 :");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[N - i - 1][j] == 1)
                    System.out.print("Q ");
                else
                    System.out.print(". ");
            }
            System.out.println();
        }
    }

    boolean isSafe(int board[][], int row, int col) {
        int i, j;
        for (i = 0; i < col; i++)
            if (board[row][i] == 1)
                return false;
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;
        for (i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    boolean solveNQUtil(int board[][], int col) {
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

    void solveNQ() {
        int board[][] = { { 0, 0, 0, 0 },
                          { 0, 0, 0, 0 },
                          { 0, 0, 0, 0 },
                          { 0, 0, 0, 0 } };

        if (!solveNQUtil(board, 0)) {
            System.out.println("Solution does not exist");
            return;
        }
        printSolution(board);
        printRevSolution(board);
    }

    public static void main(String args[]) {
        NQueens Queen = new NQueens();
        Queen.solveNQ();
    }
}
