class Solution {
public:
    int n;
    vector<int>dp;
    vector<vector<int>> pal;
     bool isPalindrome(const string &s, int i, int j) {
        if (i >= j)
            return true;

        if (pal[i][j] != -1)
            return pal[i][j];

        if (s[i] != s[j])
            return pal[i][j] = 0;

        return pal[i][j] = isPalindrome(s, i + 1, j - 1);
    }
    int solve(const string &s, int i, int k) {
        if (i >= n)
            return 0;
        if(dp[i]!=-1)return dp[i];
        int leave = solve(s, i + 1, k);
        int take = 0;
        for (int j = i + k - 1; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                take = max(take, 1 + solve(s, j + 1, k));
            }
        }
        return dp[i]=max(leave, take);
    }
    int maxPalindromes(string s, int k) {
        n = s.size();
        dp.resize(n+1,-1);
        pal.assign(n, vector<int>(n, -1));
        return solve(s, 0, k);
    }
};