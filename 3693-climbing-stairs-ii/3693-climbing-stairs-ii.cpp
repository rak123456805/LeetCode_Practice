class Solution {
public:
    vector<int>dp;
    int solve(int n, vector<int>& costs, int i) {
        if (i == n)
            return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        for(int jump=1;jump<=3;jump++){
            int j=i+jump;
            if(j<=n){
                int curr=costs[j-1]+(j-i)*(j-i)+solve(n,costs,j);
                ans=min(ans,curr);
            }
        }
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) { 
        dp.assign(n+1,-1);
        return solve(n, costs, 0); }
};