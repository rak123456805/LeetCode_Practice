class Solution {
public:
    int n;
    vector<int>dp;
    int solve(vector<int>& arr, int k,int idx){
        if(idx==n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int ans=INT_MIN;
        int res=INT_MIN;
        int j=0;
        for(int i=idx;i<min(n,idx+k);i++){
            j++;
            if(ans<arr[i])ans=arr[i];
            int sum=j*ans+solve(arr,k,i+1);
            res=max(res,sum);
        }
        return dp[idx]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        dp.assign(n+1,-1);
        return solve(arr,k,0);
    }
};