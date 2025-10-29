#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 64 // Maximum supported matrix size (power of 2)

void matrixMultiplyDC(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    int temp1[MAX][MAX], temp2[MAX][MAX];

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    matrixMultiplyDC(newSize, A11, B11, temp1);
    matrixMultiplyDC(newSize, A12, B21, temp2);
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++)
            C11[i][j] = temp1[i][j] + temp2[i][j];

    matrixMultiplyDC(newSize, A11, B12, temp1);
    matrixMultiplyDC(newSize, A12, B22, temp2);
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++)
            C12[i][j] = temp1[i][j] + temp2[i][j];

    matrixMultiplyDC(newSize, A21, B11, temp1);
    matrixMultiplyDC(newSize, A22, B21, temp2);
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++)
            C21[i][j] = temp1[i][j] + temp2[i][j];

    matrixMultiplyDC(newSize, A21, B12, temp1);
    matrixMultiplyDC(newSize, A22, B22, temp2);
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++)
            C22[i][j] = temp1[i][j] + temp2[i][j];

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int isPowerOfTwo(int n) {
    return n && (!(n & (n - 1)));
}

int main() {
    int n;
    printf("Enter matrix size (power of 2 and <= %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || !isPowerOfTwo(n)) {
        printf("Invalid size. Must be a power of 2 and less than or equal to %d.\n", MAX);
        return 1;
    }

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};

    srand(time(NULL));

    // Generate random matrices
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }

    clock_t start = clock();
    matrixMultiplyDC(n, A, B, C);
    clock_t end = clock();

    printf("\nMatrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }

    printf("\nResult matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds\n", time_taken);

    return 0;
}







