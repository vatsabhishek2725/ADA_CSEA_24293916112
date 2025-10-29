#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary Search function
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid; // found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

// Generate sorted array
void generateSortedArray(int *arr, int n) {
    arr[0] = rand() % 10 + 1; // start with positive number
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + (rand() % 10 + 1); // increasing order
    }
}

int main() {
    int result;
    int sizes[] = {50000, 60000, 70000, 80000, 90000, 100000,150000,200000,250000,1000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(0));

    printf("n\tTime_taken (seconds)\n");
    printf("-----------------------------------\n");

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));

        if (arr == NULL) {
            printf("Memory allocation failed for size %d\n", n);
            exit(1);
        }

        generateSortedArray(arr, n);

        int key = -1; // element not present (worst case)

        // measure time
        clock_t start = clock();
        for (int i = 0; i < 1000000; i++) { // repeat many times to get measurable time
            result = binarySearch(arr, n, key);
        }
        clock_t end = clock();

        double time_taken = (((double)(end - start)) / CLOCKS_PER_SEC )/ 100000.0;

        printf("%d\t%.10f\n", n, time_taken);

        free(arr);
    }

    return 0;
}