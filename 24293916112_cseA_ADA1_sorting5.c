#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate random array (for selection sort, input order doesn’t matter)
void generateRandomArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
arr[i] = rand() % 100000;
}
}

// Selection Sort
void selectionSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j;
}
}
// Swap
if (minIndex != i) {
int temp = arr[i];
arr[i] = arr[minIndex];
arr[minIndex] = temp;
}

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

generateRandomArray(arr, n);

clock_t start = clock();
selectionSort(arr, n);
clock_t end = clock();

double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("%d, %f\n", n, time_taken);

free(arr);
}
return 0;

}