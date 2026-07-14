class Solution {
public:
    int n;
    
    int solve(vector<int>& prices, int i, int buy,vector<vector<int>>&dp) {
        if (i >= n )
            return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if (buy) {
            return dp[i][buy]= max(-prices[i] + solve(prices, i + 1, 0,dp),
                       solve(prices, i + 1, 1,dp));
        }
        return dp[i][buy]=max(prices[i] + solve(prices, i + 2, 1,dp),
                   solve(prices, i + 1, 0,dp));
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices, 0, 1,dp);
    }
};