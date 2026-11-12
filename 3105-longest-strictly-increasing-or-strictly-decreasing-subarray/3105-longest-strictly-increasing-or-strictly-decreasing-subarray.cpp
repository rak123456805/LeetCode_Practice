class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int mi = 1, mx = 1;
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] > nums[i + 1]) {
                mi++;
            } else {
                ans1 = max(ans1, mi);
                mi = 1;
            }
        }
        ans1 = max(ans1, mi);
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] < nums[i + 1]) {
                mx++;
            } else {
                ans2 = max(ans2, mx);
                mx = 1;
            }
        }
        ans2 = max(ans2, mx);
        return max(ans1, ans2);
    }
};