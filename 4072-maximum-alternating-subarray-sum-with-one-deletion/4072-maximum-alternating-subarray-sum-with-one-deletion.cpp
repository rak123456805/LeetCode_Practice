class Solution {
public:

    long long dp[100005][2][2];

    long long solve(vector<int>& nums, int i, int sign, int deleted) {

        if(i == nums.size())
            return -1e18;

        if(dp[i][sign][deleted] != -1e18)
            return dp[i][sign][deleted];

        long long val;

        if(sign == 0)
            val = nums[i];
        else
            val = -nums[i];

        // Start a new subarray from nums[i]
        long long ans = val;

        // Continue current subarray
        if(sign == 0) {
            ans = max(ans,
                      nums[i] + solve(nums, i + 1, 1, deleted));
        }
        else {
            ans = max(ans,
                      -nums[i] + solve(nums, i + 1, 0, deleted));
        }

        // Delete nums[i]
        if(deleted == 0) {
            ans = max(ans,
                      solve(nums, i + 1, sign, 1));
        }

        return dp[i][sign][deleted] = ans;
    }

    long long maxAlternatingSum(vector<int>& nums) {

        for(int i = 0; i < 100005; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1e18;
                }
            }
        }

        long long ans = -1e18;

        // Start from every possible position
        for(int i = 0; i < nums.size(); i++) {

            ans = max(ans, solve(nums, i, 0, 0));
        }

        return ans;
    }
};