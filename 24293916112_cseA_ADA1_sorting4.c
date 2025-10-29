#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate random array
void generateRandomArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
arr[i] = rand() % 100000;
}
}

// Insertion Sort
void insertionSort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i];
int j = i - 1;
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key;
}
}

int main() {
// Different values of n
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

// Generate random numbers (average case)
generateRandomArray(arr, n);

clock_t start = clock();
insertionSort(arr, n);
clock_t end = clock();

double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("%d, %f\n", n, time_taken);

free(arr);
}

return 0;
}