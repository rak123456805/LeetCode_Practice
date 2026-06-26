class Solution {
public:
    bool solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size() - 1)
            return true;
        int k = nums[i];
        if (dp[i] != -1) {
            return dp[i];
        }
        for (int l = 1; l <= k; l++) {
            if (solve(nums, i + l, dp))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        bool ans = solve(nums, 0, dp);
        return ans;
    }
};