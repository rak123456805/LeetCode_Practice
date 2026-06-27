class Solution {
public:
    int n;
    int solve(vector<int>&piles,int per,int i,int m,vector<vector<vector<int>>>&dp){
        if(i>=n)return 0;
        int result=(per==1?-1:INT_MAX);
        int stones=0;
        if(dp[per][i][m]!=-1)return dp[per][i][m];
        for(int x=1;x<=min(n-i,2*m);x++){
            stones+=piles[i+x-1];
            if(per==1){
                result=max(result,stones+solve(piles,0,i+x,max(x,m),dp));
            }else{
                result=min(result,solve(piles,1,i+x,max(x,m),dp));
            }
        }
        return dp[per][i][m]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
         return solve(piles,1,0,1,dp);
    }
};