class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pri(n, 1);
        vector<int> suff(n, 1);
        pri[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pri[i] = nums[i] * pri[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i] * suff[i + 1];
        }
        vector<int> ans;
        ans.push_back(suff[1]);
        for (int i = 1; i < n - 1; i++) {
            int val = pri[i - 1] * suff[i + 1];
            ans.push_back(val);
        }
        ans.push_back(pri[n - 2]);
        return ans;
    }
};