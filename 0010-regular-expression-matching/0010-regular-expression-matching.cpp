class Solution {
public:
    int n, m;
    bool solve(string s, string p, int i, int j, vector<vector<int>>& dp) {
        if (j == p.size())
            return i == s.size();
        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (j + 1 < p.size() && p[j+1] == '*') {
            return dp[i][j] = solve(s, p, i, j + 2, dp) ||
                              (match && solve(s, p, i + 1, j, dp));
        }
        return dp[i][j] = match && solve(s, p, i + 1, j + 1, dp);
    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s, p, 0, 0, dp);
    }
};