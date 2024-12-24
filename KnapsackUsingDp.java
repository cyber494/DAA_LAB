import java.util.*;
public class KnapsackUsingDp {

    static int knapSack(int W, int weight[], int profit[], int n) {
        if (n == 0 || W == 0) {
            return 0;
        }
        if (weight[n - 1] > W) {
            return knapSack(W, weight, profit, n - 1);
        }
        int a = knapSack(W, weight, profit, n - 1);
        int b = profit[n - 1] + knapSack(W - weight[n - 1], weight, profit, n - 1);
        return Math.max(a, b);
    }

    public static void main(String[] args) {
        int profit[] = {60, 100, 120};
        int weight[] = {10, 20, 30};
        int W = 50;
        int n = profit.length;

        System.out.println(knapSack(W, weight, profit, n));
    }
}