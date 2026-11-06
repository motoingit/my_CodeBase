import java.util.List;
import java.util.ArrayList;

class Solution {

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();

        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }

        boolean[] cols = new boolean[n];
        boolean[] diag1 = new boolean[2 * n]; // row - col + n
        boolean[] diag2 = new boolean[2 * n]; // row + col

        backtrack(0, board, ans, cols, diag1, diag2);
        return ans;
    }

    private void backtrack(int row, char[][] board, List<List<String>> ans,
                           boolean[] cols, boolean[] diag1, boolean[] diag2) {

        if (row == board.length) {
            ans.add(construct(board));
            return;
        }

        for (int col = 0; col < board.length; col++) {
            int d1 = row - col + board.length;
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;

            backtrack(row + 1, board, ans, cols, diag1, diag2);

            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }

    private List<String> construct(char[][] board) {
        List<String> res = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            res.add(new String(board[i]));
        }
        return res;
    }
}

public class nQueen {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int n = 4;   // change N here
        List<List<String>> result = sol.solveNQueens(n);

        System.out.println("Total solutions: " + result.size());
        System.out.println();

        int count = 1;
        for (List<String> board : result) {
            System.out.println("Solution " + count++);
            for (String row : board) {
                System.out.println(row);
            }
            System.out.println();
        }
    }
}
