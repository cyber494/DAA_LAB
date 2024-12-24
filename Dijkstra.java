import java.util.Scanner;

public class Dijkstra {
    public static final int INFINITY = 9999;
    public static final int MAX = 10;

    public static void dijkstra(int[][] G, int n, int startnode) {
        int[][] cost = new int[MAX][MAX];
        int[] distance = new int[MAX];
        int[] pred = new int[MAX];
        int[] visited = new int[MAX];
        int count, mindistance, nextnode, i, j;

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                cost[i][j] = (G[i][j] == 0) ? INFINITY : G[i][j];

        for (i = 0; i < n; i++) {
            distance[i] = cost[startnode][i];
            pred[i] = startnode;
            visited[i] = 0;
        }

        distance[startnode] = 0;
        visited[startnode] = 1;
        count = 1;
        nextnode = 0;
        while (count < n - 1) {
            mindistance = INFINITY;

            for (i = 0; i < n; i++)
                if (distance[i] < mindistance && visited[i] == 0) {
                    mindistance = distance[i];
                    nextnode = i;
                }

            visited[nextnode] = 1;

            for (i = 0; i < n; i++)
                if (visited[i] == 0 && mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }

            count++;
        }

        for (i = 0; i < n; i++) {
            if (i != startnode) {
                System.out.print("\nDistance of node " + i + " = " + distance[i]);
                System.out.print("\nPath = " + i);
                j = i;

                do {
                    j = pred[j];
                    System.out.print(" <- " + j);
                } while (j != startnode);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] G = new int[MAX][MAX];
        int n, u;

        System.out.print("Enter the number of vertices: ");
        n = scanner.nextInt();

        System.out.println("Enter the adjacency matrix:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = scanner.nextInt();

        System.out.print("Enter the starting node: ");
        u = scanner.nextInt();

        dijkstra(G, n, u);
    }
}
