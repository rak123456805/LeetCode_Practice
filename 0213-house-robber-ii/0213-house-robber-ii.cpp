class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int>& dp) {
        if (i >n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int se = nums[i] + solve(nums, i + 2, n, dp);
        int no = solve(nums, i + 1, n, dp);
        return dp[i] = max(se, no);
    }
    int rob(vector<int>& nums) {
        vector<int> dp1, dp2;
        int n = nums.size();
        if (n == 1) return nums[0];
        dp1.assign(n, -1);
        dp2.assign(n, -1);
        int c1 = solve(nums, 0, n - 2, dp1);
        int c2 = solve(nums, 1, n - 1, dp2);
        return max(c1, c2);
    }
};