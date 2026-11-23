class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int target,int i,int sum){
        if(i==n)return sum==target?1:0;
        if(dp[i][sum+1000]!=-1)return dp[i][sum+1000];
        int plus=solve(nums,target,i+1,sum+nums[i]);
        int minus=solve(nums,target,i+1,sum-nums[i]);
        return dp[i][sum+1000]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        dp.assign(n,vector<int>(2001,-1));
        return solve(nums,target,0,0);
    }
};