class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& matrix,int i,int j){
        if (j < 0 || j >= n) return 1e9;
        if (i == n - 1) return matrix[i][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int ld=solve(matrix,i+1,j-1);
        int rd=solve(matrix,i+1,j);
        int dow=solve(matrix,i+1,j+1);
        return dp[i][j]=matrix[i][j]+min({ld,rd,dow});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        dp.assign(n,vector<int>(n+1,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,solve(matrix,0,i));
        }
        return ans;
    }
};