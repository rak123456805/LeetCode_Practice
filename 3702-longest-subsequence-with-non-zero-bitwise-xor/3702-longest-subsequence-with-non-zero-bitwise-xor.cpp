class Solution {
public:
vector<int>dp;
int n;
    int solve(vector<int>&nums,int i){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=nums[i]^solve(nums,i+1);
    }
    int longestSubsequence(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,-1);
        int to=solve(nums,0);
        if(to!=0){
            return n;
        }
        int i=0;
        while(i<n){
            int val=nums[i]^solve(nums,i+1);
            if(val!=0){
                return n-1;
            }
            i++;
        }
        return 0;
    }
};