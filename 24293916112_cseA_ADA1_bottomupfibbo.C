#include <stdio.h>
#include <time.h>

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // If n is negative, handle separately
    if (n < 0) {
        printf("Invalid input! n must be non-negative.\n");
        return 0;
    }

    int dp[n + 1]; // Array to store Fibonacci numbers

    clock_t start_time = clock();  // Start measuring time

    // Base cases
    dp[0] = 0;
    if (n >= 1)
        dp[1] = 1;

    // Build the series iteratively
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    clock_t end_time = clock();  // End measuring time

    // Display the series
    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", dp[i]);
    }
    printf("\n"); // For clean output formatting

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken); // Display execution time

    return 0;
}
