import java.util.Arrays;
import java.util.Scanner;

public class KnapSackUsingGreedy {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        float capacity, totalValue = 0;

        System.out.print("Enter the number of items: ");
        n = sc.nextInt();

        float[] weight = new float[n];
        float[] profit = new float[n];
        float[] ratio = new float[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter Weight and Profit for item[" + i + "]: ");
            weight[i] = sc.nextFloat();
            profit[i] = sc.nextFloat();
            ratio[i] = profit[i] / weight[i];
        }

        System.out.print("Enter the capacity of knapsack: ");
        capacity = sc.nextFloat();

        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        Arrays.sort(indices, (i, j) -> Float.compare(ratio[j], ratio[i]));

        for (int i : indices) {
            if (weight[i] > capacity)
                break;
            totalValue += profit[i];
            capacity -= weight[i];
        }

        if (capacity > 0 && indices.length > 0)
            totalValue += ratio[indices[indices.length - 1]] * capacity;

        System.out.println("\nThe maximum value is: " + totalValue);
        sc.close();
    }
}
