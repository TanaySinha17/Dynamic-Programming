#include <stdio.h>
#include <limits.h>

// Function to compute the minimum number of scalar multiplications
// for multiplying matrices in the given order
int matrixChainOrder(int arr[], int n) {
    // dp[i][j] will store the minimum number of scalar multiplications
    // needed to multiply matrices A[i] through A[j]
    int dp[n][n];

    // dp[i][i] = 0 for all i because no multiplication is needed for one matrix
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // l is the chain length.
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    // The answer is in dp[1][n-1], the minimum number of multiplications
    return dp[1][n-1];
}

int main() {
    // Example 1: arr = {40, 20, 30, 10, 30}
    int arr1[] = {40, 20, 30, 10, 30};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // Example 2: arr = {10, 30, 5, 60}
    int arr2[] = {10, 30, 5, 60};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Call the function and print the result
    printf("Minimum number of scalar multiplications for arr1: %d\n", matrixChainOrder(arr1, n1));
    printf("Minimum number of scalar multiplications for arr2: %d\n", matrixChainOrder(arr2, n2));

    return 0;
}
