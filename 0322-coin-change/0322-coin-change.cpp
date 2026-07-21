class Solution {
public:
    int n;

    int solve(vector<int>& coins, int amount, int j,
              vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;

        if (j < 0 || amount < 0)
            return 1e9;

        if (dp[j][amount] != -1)
            return dp[j][amount];

        int take = 1 + solve(coins, amount - coins[j], j, dp);
        int skip = solve(coins, amount, j - 1, dp);

        return dp[j][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, amount, n - 1, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};