
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> div(n, 0);

        // Calculate free items for each item type
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0) {
                    div[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for(int i = 0; i < n; i++) {
            int p = items[i][1];

            // First purchase: 0/1 knapsack
            for(int b = budget; b >= p; b--) {
                dp[b] = max(dp[b],
                    dp[b - p] + 1 + div[i]);
            }

            // Additional purchases: unbounded knapsack
            for(int b = p; b <= budget; b++) {
                dp[b] = max(dp[b],
                    dp[b - p] + 1);
            }
        }

        return dp[budget];
    }
};
