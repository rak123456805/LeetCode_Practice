class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> ans;
        long long mx = nums[0];
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > mx) {
                mx = nums[i];
            }
            ans.push_back(gcd(mx, nums[i]));
        }
        sort(ans.begin(), ans.end());
        int i = 0;
        int j = ans.size() - 1;
        long long res = 0;
        while (i < j) {
            res += gcd(ans[i], ans[j]);
            i++, j--;
        }
        return res;
    }
};