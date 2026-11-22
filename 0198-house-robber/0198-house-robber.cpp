class Solution {
public:
    int n;
    vector<int>dp;
    int solve(vector<int>&nums,int i){
        if(i>=n )return 0;
        if(dp[i]!=-1)return dp[i];
        int sel=nums[i]+solve(nums,i+2);
        int no=solve(nums,i+1);
        return dp[i]=max(sel,no);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==2){
            return max(nums[0],nums[1]);
        }
        dp.assign(n+1,-1);
        return solve(nums,0);
    }
};