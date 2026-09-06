class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s, string &t, int i, int j) {
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if (s[i] == t[j]) {
            int take = solve(s, t, i + 1, j + 1);
            int leave = solve(s, t, i + 1, j);
            return dp[i][j]=take + leave;
        }

        return dp[i][j]=solve(s, t, i + 1, j);
    }
    int numDistinct(string s, string t) { 
         int n = s.size();
        int m = t.size();

        dp.assign(n, vector<int>(m, -1));
        return solve(s, t, 0, 0); }
};