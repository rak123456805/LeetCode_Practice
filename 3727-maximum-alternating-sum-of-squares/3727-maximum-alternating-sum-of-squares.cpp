class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            long long val = 1LL * nums[i] * nums[i];
            nums[i] = val;
        }

        sort(nums.begin(), nums.end());

        long long ans = 0;
        long long res = 0;
        int n = nums.size() / 2;

        for (int i = 0; i < n; i++) {
            ans += nums[i];
        }

        for (int i = n; i < nums.size(); i++) {
            res += nums[i];
        }

        return res - ans;
    }
};