#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate worst case input (sorted ascending order)
void generateWorstCase(int arr[], int n) {
for (int i = 0; i < n; i++) {
arr[i] = i + 1; // strictly increasing → worst case for naive pivot
}
}

// Partition function
int partition(int arr[], int low, int high) {
int pivot = arr[high]; // always last element → worst case if sorted
int i = low - 1;

for (int j = low; j < high; j++) {
if (arr[j] < pivot) {
i++;
int temp = arr[i];
arr[i] = arr[j];

arr[j] = temp;
}
}
int temp = arr[i + 1];
arr[i + 1] = arr[high];
arr[high] = temp;
return (i + 1);
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
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

// Worst case input
generateWorstCase(arr, n);

clock_t start = clock();
quickSort(arr, 0, n - 1);
clock_t end = clock();

double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("%d, %f\n", n, time_taken);

free(arr);
}

return 0;
}