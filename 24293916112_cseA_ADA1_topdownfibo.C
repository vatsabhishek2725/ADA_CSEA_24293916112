#include <stdio.h>
#include <time.h>

#define MAX 1000  // Maximum size for memoization array

int dp[MAX]; // Memoization array

// Recursive function for Fibonacci (Top-Down DP)
int fib(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // If value already computed, return it
    if (dp[n] != -1)
        return dp[n];

    // Store result in dp array and return it
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Initialize memoization array with -1
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }

    clock_t start_time = clock();  // Start measuring time

    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib(i));
    }

    clock_t end_time = clock();  // End measuring time

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds\n", time_taken); // Display execution time
    
    printf("\n"); // For clean output formatting
    return 0;
}

