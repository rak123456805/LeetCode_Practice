class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool haszero = false;
        int xr = 0;
        for (int x : nums) {
            xr ^= x;
            if (x != 0) {
                haszero = true;
            }
        }
        if (xr != 0) {
            return nums.size();
        }
        if (haszero)
            return nums.size() - 1;
        return 0;
    }
};