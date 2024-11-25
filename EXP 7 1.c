#include <stdio.h>

// Function to find the maximum value of the 0/1 knapsack problem
int knapsack(int N, int W, int profit[], int weight[]) {
    int i, w;
    int dp[N+1][W+1];

    // Build the dp table in a bottom-up manner
    for (i = 0; i <= N; i++) {
        for (w = 0; w <= W; w++) {
            // Base case: if no items or no weight capacity
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // If the current item's weight is less than or equal to the remaining weight
            else if (weight[i-1] <= w) {
                dp[i][w] = (profit[i-1] + dp[i-1][w-weight[i-1]] > dp[i-1][w]) ? 
                            profit[i-1] + dp[i-1][w-weight[i-1]] : dp[i-1][w];
            }
            // Otherwise, don't include the current item
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[N][W]; // The bottom-right cell contains the maximum profit
}

int main() {
    int N1 = 4, W1 = 8;
    int profit1[] = {2, 3, 1, 4};
    int weight1[] = {3, 4, 6, 5};

    int N2 = 3, W2 = 50;
    int profit2[] = {60, 100, 120};
    int weight2[] = {10, 20, 30};

    int N3 = 4, W3 = 50;
    int profit3[] = {2, 5, 8, 1};
    int weight3[] = {10, 15, 6, 9};

    printf("Maximum profit for Test Case 1 (N = %d, W = %d): %d\n", N1, W1, knapsack(N1, W1, profit1, weight1));
    printf("Maximum profit for Test Case 2 (N = %d, W = %d): %d\n", N2, W2, knapsack(N2, W2, profit2, weight2));
    printf("Maximum profit for Test Case 3 (N = %d, W = %d): %d\n", N3, W3, knapsack(N3, W3, profit3, weight3));

    return 0;
}
