#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate random array
void createRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

// Linear search function
int searchLinear(int arr[], int target, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int sizes[] = {1000, 2000, 5000, 10000, 20000, 50000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("n\tAverage_time_per_search(seconds)\n");
    printf("------------------------------------------\n");

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed for n = %d\n", n);
            continue;
        }

        createRandomArray(arr, n);

        clock_t start = clock();
        for (int i = 0; i < 100000; i++) {
            searchLinear(arr, arr[(n-1)/2], n); // search for last element
        }
        clock_t end = clock();

        double total_time = (double)(end - start) / CLOCKS_PER_SEC;
        double avg_time = total_time / 100000.0;

        printf("%d\t%f\n", n, avg_time);

        free(arr);
    }

    return 0;
}