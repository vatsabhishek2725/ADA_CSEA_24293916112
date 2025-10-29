#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void multiplyMatrices(int n, double **a, double **b, double **result) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < n; ++k)
                result[i][j] += a[i][k] * b[k][j];
        }
}


double **allocateMatrix(int n) {
    double **matrix = malloc(n * sizeof(double *));
    for (int i = 0; i < n; ++i)
        matrix[i] = malloc(n * sizeof(double));
    return matrix;
}


void freeMatrix(double **matrix, int n) {
    for (int i = 0; i < n; ++i)
        free(matrix[i]);
    free(matrix);
}

int main() {
    int sizes[] = {10, 50, 100, 200}; 
    int numSizes = sizeof(sizes)/sizeof(sizes[0]);

    for (int s = 0; s < numSizes; ++s) {
        int n = sizes[s];
        printf("Running multiplication for matrix size: %dx%d\n", n, n);

        
        double **a = allocateMatrix(n);
        double **b = allocateMatrix(n);
        double **result = allocateMatrix(n);

        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                a[i][j] = rand() / (double)RAND_MAX;
                b[i][j] = rand() / (double)RAND_MAX;
            }

        clock_t start = clock();
        multiplyMatrices(n, a, b, result);
        clock_t end = clock();

        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Execution time for %dx%d is %.4f seconds.\n\n", n, n, elapsed);

        
        freeMatrix(a, n);
        freeMatrix(b, n);
        freeMatrix(result, n);
    }

    return 0;
}

