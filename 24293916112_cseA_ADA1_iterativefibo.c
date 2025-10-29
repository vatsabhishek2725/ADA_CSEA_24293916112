#include <stdio.h>
#include <time.h>

void printFibonacci(int n) {
    int first = 0, second = 1, next;
    printf("Fibonacci Series (Iterative): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements in the Fibonacci series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 0;
    }

    start = clock(); // Start timing
    printFibonacci(n);
    end = clock();   // End timing

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Run time: %f seconds\n", cpu_time_used);

    return 0;
}
