class Solution {
public:
    int n;
    int solve(vector<int>& cost,int i,vector<int>&dp){
        if(i==n)return 0;
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        int one=0,two=0;
        one+=cost[i]+solve(cost,i+1,dp);
        two+=cost[i]+solve(cost,i+2,dp);
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int val=solve(cost,0,dp1);
        int val2=solve(cost,1,dp2);
        return min(val,val2);
    }
};