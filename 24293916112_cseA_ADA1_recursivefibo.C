#include <stdio.h>
#include <time.h>

// Recursive Fibonacci function
int fibonacci_recursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements in the Fibonacci series: ");
    scanf("%d", &n);

    // Record start time
    start = clock();

    printf("Fibonacci Series (Recursive): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci_recursive(i));
    }

    // Record end time
    end = clock();

    // Calculate CPU time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nExecution Time: %f seconds\n", cpu_time_used);

    return 0;
}
