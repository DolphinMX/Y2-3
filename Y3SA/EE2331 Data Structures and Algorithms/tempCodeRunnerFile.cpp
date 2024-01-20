#include <iostream>
using namespace std;

// Returns the value of maximum profit using the 0/1 knapsack dynamic programming formula
int knapSack01(int W, int wt[], int val[], int n, int** dp) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; // Base case when there are no items or no weight capacity
            } else if (wt[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][W];
}

// Returns the value of maximum profit using the top-down approach with memoization
int knapSackRec(int W, int wt[], int val[], int index, int** dp) {
    if (index < 0)
        return 0;
    if (dp[index][W] != -1)
        return dp[index][W];

    if (wt[index] > W) {
        dp[index][W] = knapSackRec(W, wt, val, index - 1, dp);
        return dp[index][W];
    } else {
        dp[index][W] = max(val[index] + knapSackRec(W - wt[index], wt, val, index - 1, dp),
                           knapSackRec(W, wt, val, index - 1, dp));
        return dp[index][W];
    }
}

// Main knapsack function
int knapSack(int W, int wt[], int val[], int n, int** dp) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = -1; // Initialize with -1
        }
    }
    return knapSackRec(W, wt, val, n - 1, dp);
}

// Function to print the result table
void printResultTable(int** dp, int n, int W) {
    cout << "Result Table:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int profit[] = {4, 2, 3, 5, 1};
    int weight[] = {3, 1, 2, 3, 1};
    int W = 6;
    int n = sizeof(profit) / sizeof(profit[0]);

    // Allocate memory for the dp array
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[W + 1];
    }


    // Call the knapSack01 function with the 0/1 knapsack formula
    cout << "Maximum Profit (0/1 Knapsack): " << knapSack01(W, weight, profit, n, dp) << endl;

    // Print the final result table for 0/1 knapsack formula
    printResultTable(dp, n, W);

    // Deallocate memory for the dp array
    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}
