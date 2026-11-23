class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool solve(vector<int>&nums,int ans,int cnt,int i){
        if(ans-cnt==cnt)return true;
        if(i>=n ||cnt>ans-cnt)return false;
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        int take=solve(nums,ans,cnt+nums[i],i+1);
        int leave=solve(nums,ans,cnt,i+1);
        return dp[i][cnt]=take || leave;
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i];
        }
        if (ans % 2 != 0) return false;
        dp.assign(n + 1, vector<int>((ans / 2) + 1, -1));
        return solve(nums,ans,0,0);
    }
};