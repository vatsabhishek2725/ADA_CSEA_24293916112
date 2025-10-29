#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 64

void add(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassenMultiply(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    int P1[MAX][MAX], P2[MAX][MAX], P3[MAX][MAX], P4[MAX][MAX], P5[MAX][MAX], P6[MAX][MAX], P7[MAX][MAX];
    int tempA[MAX][MAX], tempB[MAX][MAX];

    // Divide matrices A and B into 4 submatrices each
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

    // P1 = A11 * (B12 - B22)
    subtract(newSize, B12, B22, tempB);
    strassenMultiply(newSize, A11, tempB, P1);

    // P2 = (A11 + A12) * B22
    add(newSize, A11, A12, tempA);
    strassenMultiply(newSize, tempA, B22, P2);

    // P3 = (A21 + A22) * B11
    add(newSize, A21, A22, tempA);
    strassenMultiply(newSize, tempA, B11, P3);

    // P4 = A22 * (B21 - B11)
    subtract(newSize, B21, B11, tempB);
    strassenMultiply(newSize, A22, tempB, P4);

    // P5 = (A11 + A22) * (B11 + B22)
    add(newSize, A11, A22, tempA);
    add(newSize, B11, B22, tempB);
    strassenMultiply(newSize, tempA, tempB, P5);

    // P6 = (A12 - A22) * (B21 + B22)
    subtract(newSize, A12, A22, tempA);
    add(newSize, B21, B22, tempB);
    strassenMultiply(newSize, tempA, tempB, P6);

    // P7 = (A11 - A21) * (B11 + B12)
    subtract(newSize, A11, A21, tempA);
    add(newSize, B11, B12, tempB);
    strassenMultiply(newSize, tempA, tempB, P7);

    // Calculating submatrices of result C:
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C11[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C12[i][j] = P1[i][j] + P2[i][j];
            C21[i][j] = P3[i][j] + P4[i][j];
            C22[i][j] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
    }

    // Combine submatrices into final matrix C
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
    return n && !(n & (n - 1));
}

int main() {
    int n;
    printf("Enter matrix size (power of 2 and <= %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || !isPowerOfTwo(n)) {
        printf("Invalid size. Must be a power of 2 and <= %d\n", MAX);
        return 1;
    }

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }

    clock_t start = clock();
    strassenMultiply(n, A, B, C);
    clock_t end = clock();

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
