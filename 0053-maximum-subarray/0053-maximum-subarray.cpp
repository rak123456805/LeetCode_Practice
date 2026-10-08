class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0, sum = 0, ans = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            while (sum < 0) {
                sum = 0;
                l = i + 1;
            }
        }
        return ans;
    }
};