#include <stdio.h>
#define MAX 128

void add(int n, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void sub(int n, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void strassen(int n, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    if (n == 1) {
        result[0][0] = a[0][0] * b[0][0];
        return;
    }

    int half = n / 2;
    int a11[MAX][MAX], a12[MAX][MAX], a21[MAX][MAX], a22[MAX][MAX];
    int b11[MAX][MAX], b12[MAX][MAX], b21[MAX][MAX], b22[MAX][MAX];
    int p1[MAX][MAX], p2[MAX][MAX], p3[MAX][MAX], p4[MAX][MAX], p5[MAX][MAX], p6[MAX][MAX], p7[MAX][MAX];
    int temp1[MAX][MAX], temp2[MAX][MAX];

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + half];
            a21[i][j] = a[i + half][j];
            a22[i][j] = a[i + half][j + half];
            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + half];
            b21[i][j] = b[i + half][j];
            b22[i][j] = b[i + half][j + half];
        }
    }

    add(half, a11, a22, temp1);
    add(half, b11, b22, temp2);
    strassen(half, temp1, temp2, p1);

    add(half, a21, a22, temp1);
    strassen(half, temp1, b11, p2);

    sub(half, b12, b22, temp1);
    strassen(half, a11, temp1, p3);

    sub(half, b21, b11, temp1);
    strassen(half, a22, temp1, p4);

    add(half, a11, a12, temp1);
    strassen(half, temp1, b22, p5);

    sub(half, a21, a11, temp1);
    add(half, b11, b12, temp2);
    strassen(half, temp1, temp2, p6);

    sub(half, a12, a22, temp1);
    add(half, b21, b22, temp2);
    strassen(half, temp1, temp2, p7);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            result[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
            result[i][j + half] = p3[i][j] + p5[i][j];
            result[i + half][j] = p2[i][j] + p4[i][j];
            result[i + half][j + half] = p1[i][j] - p2[i][j] + p3[i][j] + p6[i][j];
        }
    }
}
int main() {
    int n;
    printf("Enter the order of the matrices (power of 2): ");
    scanf("%d", &n);
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    printf("Enter the first matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the second matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    strassen(n, a, b, result);
    printf("Resultant matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}


// output : 
// Resultant matrix:
// 9	12	
// 19	26