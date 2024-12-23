#include <stdio.h>
int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0){
        return 0;
    }
    if (wt[n - 1] > W){
        return knapSack(W, wt, val, n - 1);
    }
    int a = knapSack(W, wt, val, n - 1);
    int b = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1);
    if(a>b){
        return a;
    }
    return b;
}

int main() {
    int profit[] = {60, 100, 120};
    int n = sizeof(profit)/sizeof(profit[0]);
    int weight[] = {10, 20, 30};
    int W = 50;

   printf("%d\n",knapSack(W, weight, profit, n));
    return 0;
}