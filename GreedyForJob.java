import java.util.*;
public class GreedyForJob {
    public static void main(String[] args) {
        int[][] arr = {
            {1, 2, 60},
            {2, 1, 100},
            {3, 3, 20},
            {4, 2, 40},
            {5, 1, 20},
        };

        Arrays.sort(arr, (a, b) -> a[1] - b[1]);

        int n = arr.length;
        int[] result = new int[n];
        Arrays.fill(result, -1);
        boolean[] slot = new boolean[n];
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = Math.min(n, arr[i][1]) - 1; j >= 0; j--) {
                if (!slot[j]) {
                    result[j] = i;
                    maxProfit += arr[i][2];
                    slot[j] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (slot[i]) {
                System.out.print(arr[result[i]][0] + " ");
            }
        }
    }
}