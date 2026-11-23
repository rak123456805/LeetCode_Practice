class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int amount,vector<int>&coins,int cnt,int i){
        if(cnt==amount)return 1;
        if(i<0 || cnt>amount)return 0;
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        int take=solve(amount,coins,cnt+coins[i],i);
        int leave=solve(amount,coins,cnt,i-1);
        return dp[i][cnt]=take+leave;
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return solve(amount,coins,0,n-1);
    }
};