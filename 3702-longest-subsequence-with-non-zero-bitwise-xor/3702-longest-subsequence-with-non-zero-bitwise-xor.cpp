class Solution {
public:
    vector<int> dp;
    int n;

    // XOR from i to n-1
    int solve(vector<int>& nums, int i) {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = nums[i] ^ solve(nums, i + 1);
    }

    int longestSubsequence(vector<int>& nums) {
        n = nums.size();

        dp.assign(n + 1, -1);

        int total = solve(nums, 0);

        // If complete array already has non-zero XOR
        if (total != 0)
            return n;

        int prefix = 0;

        for (int i = 0; i < n; i++) {

            // XOR after removing nums[i]
            int remaining = prefix ^ solve(nums, i + 1);

            if (remaining != 0)
                return n - 1;

            prefix ^= nums[i];
        }

        return 0;
    }
};