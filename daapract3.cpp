#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int maxWeight, vector<int>& values, vector<int>& weights) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][maxWeight];
}

int main() {
    int maxWeight = 12;
    vector<int> values = {30,28,20,24};
    vector<int> weights = {5, 7,4,2};

    int result = knapsack(maxWeight, values, weights);

    cout << "Maximum value: " << result << endl;

    return 0;
}
