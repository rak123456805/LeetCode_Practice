class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    bool solve(const string &s,const string &p,int i,int j){
        if (i == n && j == m) return true;
        if (j == m) return false;
        if (i == n) {
            return (p[j] == '*') ? solve(s, p, i, j + 1) : false;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s, p, i + 1, j + 1);
        }
        if (p[j] == '*') {
            return dp[i][j] = solve(s, p, i, j + 1) || solve(s, p, i + 1, j);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        n=s.size(),m=p.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(s,p,0,0);
    }
};