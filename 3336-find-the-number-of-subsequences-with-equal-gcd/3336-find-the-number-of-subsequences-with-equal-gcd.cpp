class Solution {
public:
    long long dp[201][201][201];
    long long M = 1e9 + 7;
    int n;
    long long solve(int i, int g1, int g2, vector<int>& nums) {
        if (i == n)
            return (g1 == g2 && g1 != 0);
        long long ans = 0;
        int x = nums[i];
        if (dp[i][g1][g2] != -1) {
            return dp[i][g1][g2];
        }
        ans += solve(i + 1, (g1 == 0 ? x : gcd(g1, x)), g2, nums);
        ans += solve(i + 1, g1, g2 == 0 ? x : gcd(g2, x), nums);
        ans += solve(i + 1, g1, g2, nums);
        return dp[i][g1][g2] = ans % M;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};