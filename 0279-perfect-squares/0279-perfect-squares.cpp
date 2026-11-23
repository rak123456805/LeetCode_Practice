class Solution {
public:
    vector<vector<int>>dp;
    int solve(int n,int cnt,int i){
        if(cnt==n)return 0;
        if (cnt + i * i > n) return 1e9;
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        int val=i*i;
        int take=1+solve(n,cnt+val,i);
        int leave=solve(n,cnt,i+1);
        return dp[i][cnt]=min(take,leave);
    }
    int numSquares(int n) {
        dp.assign((int)sqrt(n) + 2, vector<int>(n + 1, -1));
        return solve(n,0,1);
    }
};