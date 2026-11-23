class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>& coins, int amount,int i){
        if(amount==0)return 0;
        if (i < 0 || amount < 0)
            return 1e9;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take=1+solve(coins,amount-coins[i],i);
        int leave=solve(coins,amount,i-1);
        return dp[i][amount]= min(take,leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        int ans= solve(coins,amount,n-1);
        return ans>=1e9?-1:ans;
    }
};