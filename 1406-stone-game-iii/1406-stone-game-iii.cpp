class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& stoneValue, int i) {
        if (i >= n)
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int ans = INT_MIN;
        int sum = 0;

        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += stoneValue[i + k];
            ans = max(ans, sum - solve(stoneValue, i + k + 1));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int ans = solve(stoneValue, 0);

        if (ans > 0)
            return "Alice";
        if (ans < 0)
            return "Bob";
        return "Tie";
    }
};