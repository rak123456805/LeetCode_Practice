class Solution {
public:
    int n, m;
    bool solve(vector<vector<int>>& grid, int health, int i, int j,
               vector<vector<vector<int>>>& dp) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        if (grid[i][j] == 1)
            health--;
        if (health <= 0)
            return false;
        if (i == n - 1 && j == m - 1)
            return true;
        if (dp[i][j][health] == 2)
            return false;

        if (dp[i][j][health] != -1)
            return dp[i][j][health];

        dp[i][j][health] = 2;
        bool ans = solve(grid, health, i, j + 1, dp) ||
                   solve(grid, health, i, j - 1, dp) ||
                   solve(grid, health, i + 1, j, dp) ||
                   solve(grid, health, i - 1, j, dp);
        return dp[i][j][health] = ans;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(health + 1, -1)));
        return solve(grid, health, 0, 0, dp);
    }
};