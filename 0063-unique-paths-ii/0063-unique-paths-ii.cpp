class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&obstacleGrid,int i,int j,int m,int n){
        if (i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;
        if(i==m-1 && j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int down=solve(obstacleGrid,i+1,j,m,n);
        int right=solve(obstacleGrid,i,j+1,m,n);
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return solve(obstacleGrid,0,0,m,n);
    }
};