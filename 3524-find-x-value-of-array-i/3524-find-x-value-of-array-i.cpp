class Solution {
public:
    int n;
    vector<vector<long long>> dp;

    long long solve(int i, int j, int k, vector<int>& nums) {
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;

        // Subarray containing only nums[i]
        if (j == nums[i] % k) {
            ans++;
        }

        // Extend previous subarrays
        for (int prev = 0; prev < k; prev++) {
            if ((prev * (nums[i] % k)) % k == j) {
                ans += solve(i - 1, prev, k, nums);
            }
        }

        return dp[i][j] = ans;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        n = nums.size();

        dp.assign(n, vector<long long>(k, -1));

        vector<long long> ans(k, 0);

        // Consider every ending position
        for (int i = 0; i < n; i++) {
            for (int r = 0; r < k; r++) {
                ans[r] += solve(i, r, k, nums);
            }
        }

        return ans;
    }
};