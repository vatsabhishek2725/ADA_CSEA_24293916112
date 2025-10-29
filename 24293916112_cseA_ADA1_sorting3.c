#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate worst case array (descending order)
void generateWorstCase(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;  // largest to smallest
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Different values of n (adjust to your system capacity)
    int sizes[] = {5000, 10000, 20000, 40000};
    int num_tests = sizeof(sizes) / sizeof(sizes[0]);

    printf("n, time_sec\n");

    for (int t = 0; t < num_tests; t++) {
        int n = sizes[t];
        int *arr = (int*)malloc(n * sizeof(int));

        if (arr == NULL) {
            printf("Memory allocation failed for n = %d\n", n);
            continue;
        }

        // Worst case input
        generateWorstCase(arr, n);

        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d, %f\n", n, time_taken);

        free(arr);
    }

    return 0;
}

