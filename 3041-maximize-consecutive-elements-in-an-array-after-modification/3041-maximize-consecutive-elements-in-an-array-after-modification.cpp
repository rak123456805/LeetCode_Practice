class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int find(vector<int>&nums,int st,int ta){
        int j=lower_bound(nums.begin()+st,nums.end(),ta)-nums.begin();
        if(j<n && nums[j]==ta)return j;
        return -1;
    }
    int solve(int i,int inc,vector<int>&nums){
        int curr=nums[i]+inc;
        int len=1;
        if(dp[i][inc]!=-1)return dp[i][inc];
        //find the curr+1
        int j=find(nums,i+1,curr+1);
        if(j!=-1){
            len=max(len,1+solve(j,0,nums));
        }
        //find curr and incriment to 1
        j=find(nums,i+1,curr);
            if(j!=-1){
            len=max(len,1+solve(j,1,nums));
        }
        return dp[i][inc]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        dp.assign(n+1,vector<int>(2,-1));
        int res=1;
        for(int i=0;i<n;i++){
            res=max({res,solve(i,0,nums),solve(i,1,nums)});
        }
        return res;
    }
};